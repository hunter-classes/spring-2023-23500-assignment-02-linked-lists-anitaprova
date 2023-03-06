#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList()
{
	head = nullptr;
}

OList::~OList()
{
	Node *walker = head;
	Node *trailer = nullptr;
	while (walker != nullptr)
	{
		trailer = walker;
		walker = walker->getNext();
		delete trailer;
	}
}

void OList::insert(std::string data) // need to fix
{
	Node *walker, *trailer;
	Node *tmp = new Node(data);
	walker = head;
	trailer = nullptr;

	while (walker != nullptr && stoi(data) >= stoi(walker->getData()))
	{
		trailer = walker;
		walker = walker->getNext();
	}

	if (trailer == nullptr)
	{
		tmp->setNext(head);
		head = tmp;
	}
	else
	{
		trailer->setNext(tmp);
		tmp->setNext(walker);
	}
}

std::string OList::get(int loc)
{
	Node *tmp = this->head;
	while (loc != 0)
	{
		tmp = tmp->getNext();
		loc--;
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

void OList::reverse()
{
	Node *walker, *trailer;
	walker = this->head; // start
	trailer = nullptr;	 // behind

	while (walker != nullptr)
	{
		trailer = walker;
		walker = walker->getNext();
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
	result = result + "nullptr\n";
	return result;
}
