#include "Header.h"
#include<iostream>
#include<string>

using namespace std;

int main() {

	//create list object
	LinkedList studentList; 

	//create first student and add to list
	Student stud1;
	
	stud1.name = "Izzy";
	stud1.next = nullptr;

	studentList.push_back(stud1);

	cout << "List has been created, and first student added using push_back. The list is as follows:" << endl;
	studentList.printList();
	cout << endl;

	//creating second student
	Student stud2;
	stud2.name = "Christian";
	stud2.next = nullptr;
	 
	//output updated list to user
	studentList.push_front(stud2);
	cout << "A second student have been created and added using push_front. The list is as follows:" << endl;
	studentList.printList();
	cout << endl;

	//create 3rd and 4th students and pushback to list
	Student stud3;
	stud3.name = "Elle";
	stud3.next = nullptr;
	studentList.push_back(stud3);

	Student stud4;
	stud4.name = "Zach";
	stud4.next = nullptr;
	studentList.push_back(stud4);

	//output to user
	cout << "2 more students have been created and added using push_back. The list is as follows:" << endl;
	studentList.printList();
	cout << endl;

	//ask user to insert another student. 
	string name1;
	size_t index1;

	//ask for name 
	cout << "Let's insert another student anywhere into the list, what would you like their name to be? : ";
	cin >> name1;

	//ask for index to be inserted at
	cout << endl << "What index would you like them to be inserted at? : ";
	cin >> index1;
	cout << endl;

	//create new student based on user
	Student stud5;
	stud5.name = name1;
	stud5.next = nullptr;

	//insert new student at user choice of index
	studentList.insert(index1, stud5);

	cout << "The new student has been inserted. The list is as follows" << endl;
	studentList.printList();
	cout << endl;


	//use remove method
	size_t index2;
	cout << "Let's remove a student from the list." << endl;
	cout << "What is the index of the student you would like to remove ? : ";
	cin >> index2;

	//call remove function
	
	bool removal = studentList.remove(index2);

	if (removal == false) {
		cout << "Index invalid. No student removed." << endl;
	}

	if (removal = true) {
		cout << "Student has been removed. The updated list is as follows:" << endl;
		studentList.printList();
		cout << endl;
	}


	//show front student then pop them
	cout << "Now let's look at the first element and then remove it." << endl;
	Student first = studentList.front();
	cout << "This the first Student : " << first.name << endl;
	cout << "Now using the pop_front method, the first student will be deleted. The updated list is as follows" << endl;
	studentList.pop_front();
	studentList.printList();
	cout << endl;

	//show last student and pop them
	cout << "Now let's look at the last element and then remove it." << endl;
	Student last = studentList.back();
	cout << "This is the last Student: " << last.name << endl;
	cout << "Now using the pop_back method, the last student will be deleted. The updated list is as follows" << endl;
	studentList.pop_back();
	studentList.printList();
	cout << endl;


	//use find method
	string nameToFind;
	cout << "A lot of changes to the list have been made. What student would you like to look for?" << endl;
	cout << "enter a name: ";
	cin >> nameToFind;

	if (nameToFind == stud1.name) {
		size_t indexFound = studentList.find(stud1);

	}

	if (nameToFind == stud2.name) {
		studentList.find(stud2);
	}

	if (nameToFind == stud3.name) {
		studentList.find(stud3);
	}

	if (nameToFind == stud4.name) {
		studentList.find(stud4);
	}

	if (nameToFind == stud5.name) {
		studentList.find(stud5);
	}

	else {
		cout << "Name not found in list" << endl;
	}


	//empty list
	cout << endl << "Now let's destroy the list by calling the empty method" << endl;

	studentList.empty();
	cout << "Printing list:" << endl;
	studentList.printList();

	cout << endl << "The list is empty and the program is complete." << endl;



	return 0;
}