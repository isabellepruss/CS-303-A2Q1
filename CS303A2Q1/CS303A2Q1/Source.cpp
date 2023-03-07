#include"Header.h"


using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
	numStudents = 0;

}

LinkedList::~LinkedList() {


}

void LinkedList::printList() {

	Student* temp;
	temp = head;

	if (head == nullptr) {
		cout << "This list is empty.";

		return;
	}

	cout << head->name << endl;
	while (temp->next != nullptr) {
		temp = temp->next;
		cout << temp->name << endl;
	}

}

void LinkedList::push_back(Student& stud) {

	if (head == nullptr) {
		
		head = &stud;
		tail = &stud;

		numStudents++;

	}

	else {

		Student* temp;
		temp = head;

		while (temp->next != nullptr) {
			temp = temp->next;

		}

		temp->next = &stud;
		tail = &stud;
		numStudents++;

	}


}

void LinkedList::push_front(Student& stud) {

	if (head == nullptr) {

		head = &stud;
		tail = &stud;

		numStudents++;

	}

	else {

		Student* temp;
		temp = head;

		head = &stud;
		head->next = temp;

		numStudents++;
		
	}


}

Student LinkedList::pop_front() {

	if (head == nullptr) {
		cout << "Nothing to return, this list is empty";

		return *head;

	}

	else {

		Student* temp;
		temp = head;
		head = head->next;

		numStudents--;

		return *temp;

	}

}

Student LinkedList::pop_back() {

	if (tail == nullptr) {
		cout << "Nothing to return, this list is empty";

		return *head;

	}

	else {

		Student* temp;
		temp = head;

		while (temp->next->next != nullptr) {
			temp = temp->next;
		}

		Student* oldTail = tail;
		tail = temp;
		temp->next = nullptr;

		numStudents--;


		return *oldTail;

	}

}

Student LinkedList::front() {

	if (head == nullptr) {
		cout << "Nothing to return, this list is empty";

		return *head;

	}

	else {

		return *head;
	}

}

Student LinkedList::back() {
	if (tail == nullptr) {
		cout << "Nothing to return, this list is empty";

		return *tail;

	}

	else {

		return *tail;
	}

}

void LinkedList::empty() {

	head = nullptr;
	tail = nullptr;
	numStudents = 0;

}

void LinkedList::insert(size_t index, Student& item) {

	if (index > numStudents - 1) {

		Student tempStud = item;
		this->push_back(tempStud);
	}

	else if (index == 0) {
		Student tempStud = item;
		this->push_front(tempStud);
	}

	else {

		Student* temp1 = head;
		Student* temp2 = nullptr;

		for (int i = 0; i < index - 1; i++) {
			temp1 = temp1->next;
		}

		temp2 = temp1->next;

		temp1->next = &item;
		temp1->next->next = temp2;

		numStudents++;

	}
}

bool LinkedList::remove(size_t index) {

	if (index > numStudents - 1) {
		
		return false;
	}

	else if (index == 0) {
		
		this->pop_front();
		return true;

	}

	else if (index == numStudents-1) {

		this->pop_back();
		return true;
	}

	else {

		Student* temp1 = head;

		for (int i = 0; i < index - 1; i++) {
			temp1 = temp1->next;
		}

		temp1->next = temp1->next->next;

		return true;

	}



}

size_t LinkedList::find(const Student& item) {

	Student* temp = head;
	size_t indexCounter = 0;

	while (temp->next != nullptr) {

		if (temp->name == item.name) {

			cout << item.name << "found at index" << indexCounter << endl;
			return indexCounter ;
		}

		temp = temp->next;

		indexCounter++;

	}

	cout << item.name << " was not found in list. The size of the list is " << numStudents + 1;
	return numStudents + 1;

}

