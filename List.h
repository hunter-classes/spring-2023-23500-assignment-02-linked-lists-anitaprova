#pragma once
#include <iostream>
#include "Node.h"

class List
{
private:
  Node *head;

public:
  List();
  ~List();
  void insert(std::string data);
  void insert(int loc, std::string data); // 0 indexed
  std::string get(int loc);
  int length();
  bool contains(std::string s);
  void remove(int loc);
  std::string toString(); // for testing purposes
};
