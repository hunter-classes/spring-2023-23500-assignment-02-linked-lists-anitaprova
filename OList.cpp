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

void OList::reverse()
{
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
