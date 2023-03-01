#include <iostream>
#include "List.h"
#include "OList.h"

int main()
{
  List *l = new List();

  l->insert(0, "a");
  l->insert(0, "b");
  l->insert(0, "c");
  l->insert(0, "d");
  std::cout << l->toString() << "\n";

  std::cout << l->contains("b") << "\n";
  std::cout << l->contains("z") << "\n";

  l->insert(0, "word");
  std::cout << l->toString() << "\n";
  l->remove(0);
  std::cout << l->toString() << "\n";
  l->remove(1);
  std::cout << l->toString() << "\n";

  std::cout << "----------------------\n\n";
  OList *l = new OList();

  return 0;
}
