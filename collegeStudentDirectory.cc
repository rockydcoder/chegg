#include <iostream>
#include <string>
using namespace std;
struct Node
{
	string name, address, phone, email, id;
	Node *next;
	
};

int main() {
	ios::sync_with_stdio(false);
	int choice1, choice2;
	Node *root = new Node;
	cout << "Welcome to CoC,," << endl;
	do {
		cout << "If you are the admin, please press 1." << endl
				<< "If you are an applicant, please press 2." << endl 
				<< "Press 0 to Exit." << endl;

		cout << "Please enter your choice: " ;
		cin >> choice1;
		switch(choice1) {
			case 1:
					cout << "You are a system admin" << endl;
					do {
						cout << "Please choose an option from the menu below: " << endl;
						cout << "1- Enter a new student." << endl;
						cout << "2- Delete a student." << endl;
						cout << "3- Send a message to a student." << endl;
						cout << "4- Back to the main menu." << endl;

						cout << "Your option: ";
						cin >> choice2;
						switch(choice2) {
							case 1:
									{
										Node *newStudent = new Node;
										cout << "Please enter the student information" << endl;
										cout << "Name: ";
										cin >> newStudent->name;
										cout << "Address: ";
										cin >> newStudent->address;
										cout << "Phone: ";
										cin >> newStudent->phone;
										cout << "Email: ";
										cin >> newStudent->email;
										cout << "Student ID: ";
										cin >> newStudent->id;
										Node *iterator = root;
										while (iterator->next != 0) {
											iterator = iterator->next;
										}
										iterator->next = newStudent;
										cout << "Information has been saved successfully." << endl;

									}

									break;
							case 2:
									{
										string id;
										bool flag = false;
										cout << "Please enter a student ID to delete: ";
										cin >> id;
										Node *iterator = root, *previous;
										while (iterator->next != 0) {
											previous = iterator;
											iterator = iterator->next;
											if (iterator->id == id) {
												flag = true;
												cout << "Are you sure you want to delete "<< iterator->name <<" information?" ;
												char choice;
												cin >> choice;
												if (choice == 'Y') {
													
													previous->next = iterator->next;
													delete iterator;
													cout << "The student information has been deleted" << endl;
												}
												else {
													cout << "No deletion" << endl;
												}
												break;

											}
										}
										if (!flag) {
											cout << "Sorry, the student with this number can’t be found." << endl;
										}
										break;

									}
							case 3:
									{
										string id;
										bool flag;
										cout << "Please enter a student ID: ";
										cin >> id;
										Node *iterator = root;
										while (iterator->next != 0) {
											iterator = iterator->next;
											if (iterator->id == id) {
												flag = true;
												cout << "The following message will be sent.." << endl;
												cout << "Dear " << iterator->name << "," << endl;
												cout << "Congratulation, You have been accepted as a student in College of Computer, Qassim" << endl << "University. Your information is" << endl;
												cout << "Address: " << iterator->address << endl;
												cout << "Phone: " << iterator->phone << endl;
												cout << "Email: " << iterator->email << endl;
												cout << "Student ID: " << iterator->id << endl;
												cout << "Good Luck" << endl;
												break;
											}
										}
										if (!flag) {
											cout << "Sorry, the student with this number can’t be found." << endl;
										}
										break;
									}
						}

					} while (choice2 != 4);
					break;
			case 2:
					{
						cout << "You are an applicant." << endl;
						do {
							cout << "Please choose an option from the menu below:" << endl;
							cout << "1- Search for your name." << endl;
							cout << "2- Back to the main menu." << endl;

							cout << "Your option: ";
							cin >> choice2;
							switch(choice2) {
								case 1: 
									{
										cout << "Please enter your name: " ;
										string name;
										bool flag = false;
										cin >> name;
										Node *iterator = root;
										while (iterator->next != 0) {
											iterator = iterator->next;
											if (iterator->name == name) {
												flag = true;
												cout << "Dear " << iterator->name << "," << endl;
												cout << "Congratulation, You have been accepted as a student in College of Computer, Qassim" << endl << "University. Your information is" << endl;
												cout << "Address: " << iterator->address << endl;
												cout << "Phone: " << iterator->phone << endl;
												cout << "Email: " << iterator->email << endl;
												cout << "Student ID: " << iterator->id << endl;
												cout << "Good Luck" << endl;
												break;
											}
										}
										if (!flag) {
											cout << "Sorry, we can’t find your name in the database, please check the spelling or contact the student affair in CoC." << endl;
										}
										break;
									}
							}
						} while (choice2 != 2);
						
					}

		}
	} while (choice1 != 0);
	cout << "Thank you for using our system, Good Bye." << endl;
}