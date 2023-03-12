#pragma once
#include <iostream>
#include "Node.h"

class OList
{
private:
	Node *head;

public:
	OList();
	~OList();
	void insert(std::string data);
	std::string get(int loc);
	bool contains(std::string s);
	void remove(int loc);
	void reverse();
	Node *gethead();
	std::string toString();
};
