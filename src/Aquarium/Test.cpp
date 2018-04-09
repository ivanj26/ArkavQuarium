#include "../../include/Animal/Guppy.hpp"
#include "../../include/LinkedList/Node.hpp"
#include "../../include/LinkedList/LinkedList.hpp"
#include <iostream>

using namespace std;

int main(){
  LinkedList<Fish*> linkedList;
  Guppy *guppy = new Guppy();
  guppy->setX(9);
  guppy->setY(10);

  linkedList.add(guppy);
  guppy = nullptr;

  Guppy *i = new Guppy();
  i->setX(89);
  i->setY(100);

  linkedList.add(i);
  i = nullptr;

  i = new Guppy();
  i->setX(6);
  i->setY(100);

  linkedList.add(i);
  delete guppy;
  delete i;

  // for (int i = 0; i < linkedList.getCurrentSize(); i++){
  //   Guppy *t = dynamic_cast<Guppy*>(linkedList.getIndex(i));
  //   cout << t->getX() << " " << t->getY() << endl;
  //   t = nullptr;
  // }
  Fish *u = (linkedList.getIndex(2));
  cout << " " << u->getX() << endl;
  Guppy *t = dynamic_cast<Guppy*>(linkedList.getIndex(1));
  cout << " " << t->getX() << endl;
  // Guppy guppy;
  //
  // guppy.setX(25);
  // guppy.setY(70);
  //
  // fishes.add(guppy);
  return 0;
}
