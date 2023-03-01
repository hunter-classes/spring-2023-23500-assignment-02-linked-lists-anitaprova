#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList()
{
	head = nullptr;
}

OList::~OList()
{
	delete head;
}

void OList::insert(std::string data)
{
	Node *tmp = new Node(data);
	tmp->setNext(head);
	head = tmp;
}

void OList::insert(int loc, std::string data)
{
	Node *walker, *trailer;
	walker = this->head; // start of the list
	trailer = nullptr;	 // one behind

	while (loc > 0 && walker != nullptr)
	{
		loc = loc - 1;

		trailer = walker;
		walker = walker->getNext();
	}

	if (loc > 0)
	{
		throw std::out_of_range("Our insert is out of range");
	}

	Node *newNode = new Node(data);
	if (trailer == nullptr)
	{
		newNode->setNext(head);
		head = newNode;
	}
	else
	{
		// do the regular case
		newNode->setNext(walker);
		trailer->setNext(newNode);
	}
}

int OList::length()
{
	Node *tmp = this->head;
	int count = 0;
	while (tmp != nullptr)
	{
		count++;
		tmp = tmp->getNext();
	}
	return count;
}

std::string OList::get(int loc)
{
	Node *tmp = this->head;
	int i = 0;
	while (i != loc - 1)
	{
		tmp = tmp->getNext();
		i++;
	}
	return tmp->getData();
}

bool OList::contains(std::string s)
{
	Node *tmp = this->head;
	while (tmp != nullptr)
	{
		if (tmp->getData() == s)
		{
			return true;
			break;
		}

		tmp = tmp->getNext();
	}
	return false;
}

void OList::remove(int loc)
{
	Node *walker, *trailer;
	walker = this->head; // start
	trailer = nullptr;	 // behind

	while (loc > 0 && walker != nullptr)
	{
		loc--;
		trailer = walker;
		walker = walker->getNext();
	}

	if (trailer == nullptr)
	{ // special case
		head = walker->getNext();
	}
	else
	{
		trailer->setNext(walker->getNext());
	}
}

std::string OList::toString()
{
	Node *tmp = this->head;
	std::string result = "";
	while (tmp != nullptr)
	{
		result = result + tmp->getData();
		result = result + "-->";
		tmp = tmp->getNext();
	}
	result = result + "nullptr";
	return result;
}
