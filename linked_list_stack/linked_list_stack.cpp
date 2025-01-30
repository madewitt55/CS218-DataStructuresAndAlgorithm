// Mason DeWitt; mason.dewitt@snhu.edu; ID: 2595261
// linked_list_stack.cpp: User interface to view and modify a stack of students

#include <iostream>
#include "LinkedStack.h"
using namespace std;

// Prompt user to input data to generate student
StudentInfo InputStudent() {
	StudentInfo student;
	cout << "\nEnter id: ";
	cin >> student.id;
	cout << "Enter phone number: ";
	cin >> student.phone_number;
	cout << "Enter name: ";
	cin >> student.name;
	cout << "Enter address: ";
	cin >> student.address;
	cout << endl;

	return student;
}

// Display all info about a student
void DisplayStudent(StudentInfo student) {
	cout << "\nId: " << student.id << endl;
	cout << "Phone number: " << student.phone_number << endl;
	cout << "Name: " << student.name << endl;
	cout << "Address: " << student.address << endl << endl;
}

int main()
{
	LinkedStack<StudentInfo> stack;
	int choice = 0;
	string answer;

	cout << "Select an option to interact with array-based stack" << endl;
	do {
		cout << "\n1. Push element to stack" << endl;
		cout << "2. Pop element from stack" << endl;
		cout << "3. Get size of stack" << endl;
		cout << "4. Check if stack is empty" << endl;
		cout << "5. Check if stack is full" << endl;
		cout << "6. Retrieve top item of stack" << endl;
		cout << "-1: Exit" << endl;
		cin >> choice;

		switch (choice) {
			// Push element
			case 1:
				if (!stack.IsFull()) {
					stack.Push(InputStudent());
				}
				else {
					cout << "Stack is full, cannot push" << endl;
				}
				break;
			// Pop element
			case 2:
				if (!stack.IsEmpty()) {
					stack.Pop();
					if (!stack.IsEmpty()) {
						cout << "Student now on top of stack:" << endl;
						DisplayStudent(stack.GetTop());
					}
					else {
						cout << "Stack is now empty" << endl;
					}
				}
				else {
					cout << "Stack is empty, cannot pop" << endl;
				}
				break;
			// Get size
			case 3:
				cout << stack.Size() << endl;
				break;
			// Check if empty
			case 4:
				answer = stack.IsEmpty() ? "Stack is empty" : "Stack is not empty";
				cout << answer << endl;
				break;
			// Check if full
			case 5:
				answer = stack.IsFull() ? "Stack is full" : "Stack is not full";
				cout << answer << endl;
				break;
			// Get top of stack
			case 6:
				if (!stack.IsEmpty()) {
					DisplayStudent(stack.GetTop());
				}
				else {
					cout << "Stack is empty, cannot display top" << endl;
				}
				break;
		}
	} while (choice != -1); // Exit on -1
}
