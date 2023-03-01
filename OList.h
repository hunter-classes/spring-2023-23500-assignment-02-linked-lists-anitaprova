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
	void insert(int loc, std::string data);
	std::string get(int loc);
	int length();
	bool contains(std::string s);
	void remove(int loc);
	std::string toString();
};
