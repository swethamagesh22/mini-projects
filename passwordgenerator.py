#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun May 28 10:57:10 2023

@author: swetha
"""
from tkinter import *
import pyperclip
import random
import string

root = Tk()
root.geometry("700x500")
root.title("Password Generator")

passnum = IntVar()
passnum.set(0)
passlen = IntVar()
passlen.set(0)
serial_num = IntVar()


def generate():  # Function to generate the password
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase
    numbers = string.digits
    symbols = string.punctuation

    password_list = []
    for i in range(passnum.get()):
        password = []
        password.extend(random.choice(lowercase))
        password.extend(random.choice(uppercase))
        password.extend(random.choice(numbers))
        password.extend(random.choice(symbols))
        password.extend(random.choice(lowercase + uppercase + numbers + symbols) for _ in range(passlen.get() - 4))
        random.shuffle(password)
        password_str = ''.join(password)
        password_list.append((i + 1, password_str))  # Add serial number to the password

    passwords_display.delete(1.0, END)  # Clear previous content
    for password in password_list:
        passwords_display.insert(END, f"{password[0]}. {password[1]}\n")


def copyclipboard():
    selected_serial_num = serial_num.get()
    for password in passwords_display.get("1.0", END).splitlines():
        if password.startswith(f"{selected_serial_num}. "):
            selected_password = password.split(". ")[1]
            pyperclip.copy(selected_password)
            message_display.config(text="Password copied successfully!", font="Courier 13 bold", fg="green")
            root.after(1000, blink_message)
            break
    else:
        message_display.config(text="Invalid serial number!", font="Courier 13 bold", fg="red")


def blink_message():
    current_fg_color = message_display.cget("foreground")
    next_fg_color = "green" if current_fg_color == "white" else "white"
    message_display.config(fg=next_fg_color)
    root.after(1000, blink_message)


Label(root, text="Number of passwords to be generated", font="Courier 13 bold").pack(pady=3)
Entry(root, textvariable=passnum).pack(pady=3)
Label(root, text="Enter length of the password", font="Courier 13 bold").pack(pady=3)
Entry(root, textvariable=passlen).pack(pady=3)
Button(root, text="Generate", command=generate).pack(pady=7)
passwords_display = Text(root, height=10)
passwords_display.pack(padx=10)
Label(root, text="Enter serial number to copy", font="Courier 13 bold").pack(pady=3)
Entry(root, textvariable=serial_num).pack(pady=3)
Button(root, text="Copy Selected to Clipboard", command=copyclipboard).pack()
message_display = Label(root, text="")
message_display.pack()

root.mainloop()
