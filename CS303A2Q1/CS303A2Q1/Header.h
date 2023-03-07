#pragma once
#include<string>
#include<iostream>

using namespace std;

struct Student {

	string name;
	Student* next;

};


class LinkedList {

private:
	Student* head;
	Student* tail;
	int numStudents;


public:
	LinkedList();
	~LinkedList();

	void printList();
	void push_back(Student& stud);
	void push_front(Student& stud);
	Student pop_front();
	Student pop_back();
	Student front();
	Student back();
	void empty();
	void insert(size_t index, Student& item);
	bool remove(size_t index);
	size_t find(const Student& item);
};
