#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();

  l->insert(0, "b");
  l->insert(0, "c");
  l->insert(0, "d");

  std::cout << l->contains("b") << "\n";
  std::cout << l->contains("z") << "\n";
  
  l->insert(0, "word");

  return 0;
}
