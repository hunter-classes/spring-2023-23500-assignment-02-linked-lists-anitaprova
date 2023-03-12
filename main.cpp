#include <iostream>
#include "Node.h"
#include "List.h"
#include "OList.h"

int main()
{
  OList *m = new OList();
  m->insert("0");
  m->insert("1");
  m->insert("2");
  m->insert("4");
  m->insert("3");
  m->insert("5");

  std::cout << m->get(0) << "\n";
  std::cout << m->get(3) << "\n";

  std::cout << m->contains("6") << "\n";
  std::cout << m->contains("0") << "\n";

  std::cout << m->toString() << "\n";
  m->remove(0);
  std::cout << m->toString() << "\n";

  std::cout << m->toString() << "\n";
  m->remove(3);
  std::cout << m->toString() << "\n";

  m->reverse();
  std::cout << m->toString() << "\n";

  return 0;
}
