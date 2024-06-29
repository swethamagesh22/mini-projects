#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May 29 08:45:18 2023

@author: swetha
"""

import tkinter as tk
from tkinter import ttk
import psutil 

def get_processes():
    processes = []
    
    for process in psutil.process_iter(['pid', 'ppid', 'username', 'cpu_percent', 'memory_percent', 'name']):
        processes.append({
            'pid': process.info['pid'],
            'ppid': process.info['ppid'],
            'user': process.info['username'],
            'cpu_percent': process.info['cpu_percent'],
            'mem_percent': process.info['memory_percent'],
            'name': process.info['name']
        })
    
    return processes

def categorize_processes(processes):
    categorized_processes = {'cpu_bound': [], 'io_bound': []}
    
    for process in processes:
        cpu_percent = process['cpu_percent']
        mem_percent = process['mem_percent']
        
        if cpu_percent is not None and mem_percent is not None:
            if cpu_percent > mem_percent:
                process['category'] = 'CPU Bound'
                categorized_processes['cpu_bound'].append(process)
            else:
                process['category'] = 'I/O Bound'
                categorized_processes['io_bound'].append(process)
    
    return categorized_processes

def get_process_utilization(pid):
    try:
        process = psutil.Process(pid)
        cpu_percent = process.cpu_percent()
        mem_percent = process.memory_percent()
        rss = process.memory_info().rss
        name = process.name()
        
        return cpu_percent, mem_percent, rss, name
    except psutil.NoSuchProcess:
        pass
    
    return None

def refresh_processes():
    processes = get_processes()
    categorized_processes = categorize_processes(processes)
    
    # Clear existing treeview
    for item in process_treeview.get_children():
        process_treeview.delete(item)
    
    # Insert CPU-bound processes
    for process in categorized_processes['cpu_bound']:
        process_treeview.insert('', 'end', values=(process['pid'], process['name'], process['cpu_percent'], process['mem_percent'], 'CPU Bound'))
    
    # Insert I/O-bound processes
    for process in categorized_processes['io_bound']:
        process_treeview.insert('', 'end', values=(process['pid'], process['name'], process['cpu_percent'], process['mem_percent'], 'I/O Bound'))
    
    # Schedule next refresh after 5 seconds
    root.after(5000, refresh_processes)

def get_selected_pid():
    # Retrieve the selected item's PID from the treeview
    selected_item = process_treeview.focus()
    if selected_item:
        item_values = process_treeview.item(selected_item)['values']
        return item_values[0]
    return None

def show_utilization(process_treeview):  # Pass process_treeview as an argument
    pid = get_selected_pid()
    if pid:
        utilization = get_process_utilization(pid)
        if utilization:
            cpu_percent, mem_percent, rss, name = utilization
            utilization_text.set(f"PID: {pid}\n"
                                 f"CPU Percent: {cpu_percent}\n"
                                 f"Memory Percent: {mem_percent}\n"
                                 f"Resident Set Size (RSS): {rss} bytes\n"
                                 f"Name: {name}")
        else:
            utilization_text.set(f"Process with PID {pid} not found.")
            utilization_text.set("No process selected.")

# Create the main window
root = tk.Tk()
root.title("Process Management Viewer")

# Create a Treeview widget to display processes
process_treeview = ttk.Treeview(root, columns=("PID", "Name", "CPU Percent", "Memory Percent", "Category"))
process_treeview.heading("PID", text="PID")
process_treeview.heading("Name", text="Name")
process_treeview.heading("CPU Percent", text="CPU Percent")
process_treeview.heading("Memory Percent", text="Memory Percent")
process_treeview.heading("Category", text="Category")
process_treeview.pack()

# Create a button to refresh processes
refresh_button = ttk.Button(root, text="Refresh", command=refresh_processes)
refresh_button.pack()

# Create a label to display process utilization
utilization_text = tk.StringVar()
utilization_label = ttk.Label(root, textvariable=utilization_text, wraplength=300)
utilization_label.pack()

# Create a button to show process utilization
show_utilization_button = ttk.Button(root, text="Show Utilization", command=lambda: show_utilization(process_treeview))
show_utilization_button.pack()

# Refresh the processes initially
refresh_processes()

# Start the GUI event loop
root.mainloop()
