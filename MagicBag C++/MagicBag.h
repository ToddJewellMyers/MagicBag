#pragma once
/*
Todd J Myers
5/28/21
*/

#include <iostream>
#include <exception>

using namespace std;

// Node structure for containing item values
struct Node 
{
	int value;
	struct Node* next;
};

// Empty bag exception
class myexception : public exception
{
	virtual const char* what() const throw() {
		return "\nMagicBag is empty.";
	}
} myex;

class MagicBag
{
public:
	MagicBag();
	MagicBag(const MagicBag& other);
	void insert(int item);
	int draw();
	int peek(int item);
	friend ostream& operator<<(ostream& os, const MagicBag& bg);
private:
	struct Node* head;
	int size;
};

// Constructor
MagicBag::MagicBag() 
{
	head = NULL;
	size = 0;
}

// Copy constructor
MagicBag::MagicBag(const MagicBag& other)
{
	head = NULL;
	size = 0;
	if (other.size == 0) 
	{
		return;
	}

	Node* ptr = other.head;
	while (ptr != NULL) 
	{
		Node* newnode = new Node;
		newnode->value = ptr->value;
		newnode->next = head;
		head = newnode;
		size++;
		ptr = ptr->next;
	}
}

// Add item into bag
void MagicBag::insert(int item)
{
	Node* newnode = new Node;
	newnode->value = item;
	newnode->next = head;
	head = newnode;
	size++;
}

// Remove random item from bag
int MagicBag::draw()
{
	// Determine if item can be removed from bag
	try {
		if (size == 0)
		{
			throw myex;
		}
	}
	catch (exception& e) {
		cout << e.what() << '\n';
	}

	int random;
	srand(time(0));
	// If there is only 1 item in the bag then remove it
	if (size == 1) 
	{
		random = 0;
	}
	else 
	{
		random = rand() % (size - 1);
	}

	/ /Remove head node
	if (random == 0) 
	{
		Node* ptr = head;
		int value = ptr->value;
		head = head->next;
		delete ptr;
		size--;
		return value;
	}

	// Remove nonhead node
	Node* ptr;
	ptr = head;
	while ((random - 1) != 0) 
	{
		ptr = ptr->next;
		random--;
	}

	Node* deleteptr;
	deleteptr = ptr->next;
	ptr->next = ptr->next->next;
	int value = deleteptr->value;
	delete deleteptr;
	size--;
	return value;
}

// Returns count of requested item
int MagicBag::peek(int item)
{
	int count = 0;

	if (size == 0)
	{
		return count;
	}
	else {
		Node* ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->value == item) 
			{
				count++;
			}
			ptr = ptr->next;
		}
	}

	return count;
}

ostream& operator<<(ostream& os, const MagicBag& bg) 
{
	os << "[";
	Node* ptr;
	ptr = bg.head;
	while (ptr != NULL) {
		os << ptr->value << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;
}