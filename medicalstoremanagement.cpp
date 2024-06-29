
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <sstream>

#define max 100

using namespace std;

class medicineType 
{
public:
	int init;
	void take_order();	  // to  take_order
	void delete_order();  // to delete the order
	void modify();		  // to modify the order
	void order_list();	  // to display the order_list
	void daily_summary(); // to display daily_summary
	void exit();		  // function to exit system
	medicineType();		  // constuctor
};

medicineType::medicineType()
{
	init = 0;

struct node // constract node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[100];
	string type = {"OTC"};
	int x, menu2[100];
	double amount[100];
	string medicineName[100] = {"Probiotics", "Vitamin C(500mg)", "Acid Free C(500mg)", "Women'S Multivate", "Marino Tablet", "Maxi Cal Tablet",
							   "Amino Zinc Tablet", "Burnex", "Fabuloss 5", "Royal Propollen", "Cetrizine", "Monocef (250mg)", "Dolo 650", "Paracetamol", "Cureveda", "Durex", "Savlon", "Cotton", "Nicip", "Benadryl", "Flexon", "Vicks", "Volini", "Crepe bandage"};
	double Medicine[100] = {32.00, 60.00, 89.00, 140.00, 132.00, 95.00, 57.00, 49.00, 73.00, 56.00, 20.00, 240.00, 69.00, 500.00, 945.00, 50.00, 79.00, 23.00, 12.00, 110.00, 4.00, 59.60, 130.00, 410.00};
	double total;

	node *prev;
	node *next;
	node *link;

} * q, *temp; // pointer declaration

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

template <typename T>
T name1(T x)
{
	return x;
}
template <typename T>
T name2(T x)
{
	return x;
}
template <typename T>
T name3(T x)
{
	return x;
}
template <typename T>
T name4(T x)
{
	return x;
}

int main() // Main function
{
	
	medicineType medicine;
	int menu;
	do
	{
		//system("cls");
		cout << "----------------------------------------------------\n";
		cout << "------| SRM Medical Store Management System |------- \n";
		//cout << "\t\t  ==================================================\n\n";
		cout << "----------------------------------------------------\n";
		cout << "\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout << "\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout << "\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout << "\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout << "\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout << "\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout << "\t\t||\tMember: " << name1("Swetha Magesh") << " & " << name2("Noore Hera") << " " << "\t ||\n";
		cout << "Enter choice: ";

		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			medicine.take_order(); // function add
			break;
		} // end case 1

		case 2:
		{
			medicine.delete_order(); // function delete
			//system("PAUSE");
			break;
		} // end case 2

		case 3:
		{
			medicine.modify(); // function modify
			//system("PAUSE");
			break;
		} // end case 3

		case 4:
		{
			medicine.order_list(); // function order
			//system("PAUSE");
			break;
		} // end case 4
		case 5:
		{
			medicine.daily_summary(); // function daily_summary
			//system("PAUSE");
			break;
		} // end case 5
		case 6:
		{
			medicine.exit(); // function exit
			goto a;
			break;
		} // end case 6

		default:
		{
			cout << "You enter invalid input\nre-enter the input\n"
				 << endl;
			break;
		}
		}
	} while (menu != 6);
a:
	cout << "Thank you" << endl;
	//system("PAUSE");
	return 0;
} // end  main function

void medicineType::take_order()
{

	//system("cls");
	int i;
	int choice, quantity, price, None;

	cout << "\nAdd Order Details\n";
	cout << "_____________________________________ \n\n";

	node *temp;
	temp = new node;

	cout << "**************************************************************************\n";
	cout << "DRUGS ID"
		 << "\tDRUGS TYPE"
		 << "   \t\tDRUGS NAME"
		 << "           DRUGS PRICE(Rs)" << endl;
	cout << "**************************************************************************\n";
	cout << "0001"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Probiotics"
		 << "			            RS 32.00" << endl;
	cout << "0002"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Vitamin C(500mg)"
		 << "		        RS 60.00" << endl;
	cout << "0003"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Acid Free C(500mg)"
		 << "		        RS 89.00" << endl;
	cout << "0004"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Women'S Multivate"
		 << "		        RS 140.00" << endl;
	cout << "0005"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Marino Tablet"
		 << "	 	            RS 132.00" << endl;
	cout << "0006"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Maxi Cal Tablet"
		 << " 		        RS 95.00" << endl;
	cout << "0007"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Amino Zinc Tablet"
		 << "		        RS 57.00" << endl;
	cout << "0008"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Burnex"
		 << "			                RS 49.00" << endl; // 1353fn
	cout << "0009"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Fabuloss 5"
		 << "			            RS 73.00" << endl;
	cout << "0010"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Royal Propollen"
		 << "		            RS 56.00" << endl;
	cout << "0011"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Cetrizine"
		 << "		                RS 20.00" << endl;
    cout << "0012"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Monocef (250Mg)"
		 << "		            RS 240.00" << endl;
	cout << "0013"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Dolo 650"
		 << "		                RS 69.00" << endl;
	cout << "0014"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Paracetamol"
		 << "		                RS 500.00" << endl;
	cout << "0015"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Cureveda"
		 << "		                RS 945.00" << endl;
	cout << "0016"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Durex"
		 << "		                    RS 50.00" << endl;
	cout << "0017"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    savlon"
		 << "		                    RS 79.00" << endl;
	cout << "0018"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Cotton"
		 << "		                    RS 23.00" << endl;
	cout << "0019"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Nicip"
		 << "		                    RS 12.00" << endl;
	cout << "0020"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Benadryl"
		 << "		                RS 110.00" << endl;
	cout << "0021"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Flexon"
		 << "		                    RS 4.00" << endl;
	cout << "0022"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Vicks"
		 << "		                    RS 59.60" << endl;
	cout << "0023"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Volini"
		 << "		                    RS 130.00" << endl;
	cout << "0024"
		 << "\t"
		 << "\tOTC"
		 << "\t\t"
		 << "    Crepe bandage"
		 << "		            RS 410.00" << endl;
	cout << " " << endl;
	// Dynamic Memory Allocation
	temp = new node;
	cout << "Type Order no: ";
	cin >> temp->reciept_number;
	cout << "Enter Customer Name: ";
	cin >> temp->customerName;
	cout << "Enter Date : ";
	cin >> temp->date;
	cout << "How many Medicine would you like to order:" << endl;
	cout << "( Maximum is 100 order for each transaction ) \n";
	cout << "  ";
	cin >> temp->x;
	if (temp->x > 100)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		//system("pause");
	}
	else
	{
		for (i = 0; i < temp->x; i++)
		{

			cout << "Please enter your selection : " << endl;
			cin >> temp->menu2[i];
			cout << "Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
			cout << "How many medicine do you want: ";
			cin >> temp->quantity[i];
			temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
			cout << "The amount You need to pay is: "
				 << " RS." << temp->amount[i] << endl;
			//system("PAUSE");
		}
		cout << "===========================================================================" << endl;
		cout << "Order Taken Successfully" << endl;
		cout << "===========================================================================" << endl;
		cout << "Go to Reciept Menu to Pay The Bill" << endl;
		cout << "===========================================================================" << endl;
		//system("PAUSE");

		temp->next = NULL;
		if (start_ptr != NULL)
		{
			temp->next = start_ptr;
		}
		start_ptr = temp;
		//system("cls");
	}

} // End function take_order

void medicineType::order_list() // Function to display receipt
{

	ofstream fout("data.txt");
	// fout << "adad"; // write data to the file student
	int i, num, num2;
	bool found; // variable to search
	//system("cls");
	node *temp;

	temp = start_ptr;
	found = false;

	cout << " Enter the Reciept Number To Print The Reciept\n";
	cin >> num2;
	cout << "\n";
	cout << "===========================================================================" << endl;
	fout << "===========================================================================" << endl;
	cout << "\t\tHere is the Order list\n";
	fout << "\t\tHere is the Order list\n";
	cout << "===========================================================================" << endl;
	fout << "===========================================================================" << endl;

	if (temp == NULL) // Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while (temp != NULL && !found)
	{
		if (temp->reciept_number == num2)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
		if (found) // print the receipt
		{
			cout << "Reciept Number : " << temp->reciept_number;
			fout << "Reciept Number : " << temp->reciept_number;
			cout << "\n";
			fout << "\n";
			cout << "Customer Name: " << temp->customerName << endl;
			fout << "Customer Name: " << temp->customerName << endl;

			cout << "Order Date : " << temp->date << endl;
			fout << "Order Date : " << temp->date << endl;

			cout << "_____________________________________________________________________________" << endl;
			fout << "_____________________________________________________________________________" << endl;

			cout << "===============================================================================" << endl;
			fout << "===============================================================================" << endl;
			cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
			fout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++===============" << endl;
			fout << "=======++==================++================++===============++===============" << endl;
			for (i = 0; i < temp->x; i++)
			{
				cout << temp->type << "  \t\t";
				fout << temp->type << "  \t\t";
				cout << temp->medicineName[temp->menu2[i] - 1] << "\t\t\t  ";
				fout << temp->medicineName[temp->menu2[i] - 1] << "\t\t\t  ";
				cout << temp->quantity[i] << "\t\t";
				fout << temp->quantity[i] << "\t\t";
				cout << temp->amount[i] << " RS." << endl;
				fout << temp->amount[i] << " RS." << endl;
				cout << "_________________________________________________________________________________" << endl;
				fout << "_________________________________________________________________________________" << endl;
			}

			temp->total = temp->amount[0] + temp->amount[1] + temp->amount[2] + temp->amount[3] + temp->amount[4] + temp->amount[5] + temp->amount[6] + temp->amount[7] + temp->amount[8] + temp->amount[9];
			cout << "Total Bill is : " << temp->total;
			fout << "Total Bill is : " << temp->total;
			cout << "\n";
			fout << "\n";
			cout << "Type the exact amount You need to pay: ";
			cin >> num;
			if (temp->total != num)
			{
				cout << "\n";
				cout << "Purey Paise De Bhai !!!\n";
			}
			else
			{
				cout << "\n";
				cout << "\n";
				cout << "Payment Done\nThank You\n";
				cout << "\n_______________________________________________________________________________\n";
			}
		}
	}
	fout.close();
} // End function order_list

void medicineType::delete_order() // function to delete_order
{
	//system("cls");
	int i, num, count;
	cout << "Enter the data you want to delete \n";
	cin >> num;
	node *q;
	node *temp;
	bool found;

	if (start_ptr == NULL)
		cerr << "Can not delete from an empty list.\n";
	else
	{
		if (start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if (start_ptr == NULL)
				last = NULL;
			delete q;
			cout << "The Reciept is Deleted Successfully" << endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;

			while ((!found) && (q != NULL))
			{
				if (q->reciept_number != num)
				{
					temp = q;
					q = q->next;
				}
				else
					found = true;
			}

			if (found)
			{
				temp->next = q->next;
				count--;

				if (last == q)
					last = temp;
				delete q;
				cout << "The Reciept is Deleted Successfully" << endl;
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
} // End function delete_order

void medicineType::modify() // function to modify order
{
	//system("cls");
	int i, ch, sid;
	bool found;
	found = false;
	temp = start_ptr;
	cout << "Enter Receipt Number To Modify: ";
	cin >> sid;
	if (temp == NULL && sid == 0)
	{
		cout << "NO RECORD TO MODIFY..!" << endl;
	}

	else
	{
		while (temp != NULL && !found)
		{
			if (temp->reciept_number == sid)
			{
				found = true;
			}
			else
			{
				temp = temp->next;
			}
			if (found)
			{
				cout << "Change  Order Number: ";
				cin >> temp->reciept_number;
				cout << "Change Customer Name: ";
				cin >> temp->customerName;
				cout << "Change Date : ";
				cin >> temp->date;
				cout << "How many New Medicine would you like to Change:" << endl;
				cout << "( Maximum is 10 order for each transaction ) \n";
				cout << "  ";
				cin >> temp->x;
				if (temp->x > 10)
				{
					cout << "The Medicine you order is exceed the maximum amount of order !";
					//system("pause");
				}
				else
				{
					for (i = 0; i < temp->x; i++)
					{

						cout << "Please enter your selection to Change: " << endl;
						cin >> temp->menu2[i];
						cout << "Change Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
						cout << "How many New medicine do you want: ";
						cin >> temp->quantity[i];
						temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
						cout << "The amount You need to pay After Modify  is: " << temp->amount[i] << " RS" << endl;
						//system("PAUSE");
					}
					temp = temp->next;
					//system("cls");
				}

				cout << "RECORD MODIFIED....!" << endl;
			}
			else
			{
				if (temp != NULL && temp->reciept_number != sid)
				{
					cout << "Invalid Reciept Number...!" << endl;
				}
			}
		}
	}
} // End modify function

void medicineType::daily_summary() // Function to display Daily Summary
{
	int i, num;
	//system("cls");
	node *temp;

	temp = start_ptr;

	if (temp == NULL) // Invalid receipt code
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout << "\n";
		cout << "===========================================================================" << endl;
		cout << " \t\tHere is the Daily Summary of All Orders \n"; // print all receipt
		cout << "===========================================================================" << endl;

		while (temp != NULL)
		{

			cout << "Reciept Number : " << temp->reciept_number;
			cout << "\n";
			cout << "Customer Name: " << temp->customerName << endl;

			cout << "Order Date : " << temp->date << endl;

			cout << "____________________________________________________________________________" << endl;

			cout << "==========================================================================" << endl;
			cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++==========" << endl;
			for (i = 0; i < temp->x; i++)
			{
				cout << temp->type << "  \t\t";
				cout << temp->medicineName[temp->menu2[i] - 1] << "\t\t";
				cout << temp->quantity[i] << "\t\t";
				cout << temp->amount[i] << " RS" << endl;
				cout << "_____________________________________________________________________________" << endl;
			}

			temp->total = temp->amount[0] + temp->amount[1] + temp->amount[2] + temp->amount[3] + temp->amount[4] + temp->amount[5] + temp->amount[6] + temp->amount[7] + temp->amount[8] + temp->amount[9];
			cout << "Total Bill is : " << temp->total;

			cout << "\n";
			cout << "\n";
			cout << "\n_______________________________________________________________________________\n";

			temp = temp->next;
		}
	}
} // End daily summary
void medicineType::exit() // Function to exit
{
	cout << "\nYou choose to exit.\n"
		 << endl;
} // end function exit

