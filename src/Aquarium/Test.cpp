#include "../../include/Animal/Guppy.hpp"
#include "../../include/LinkedList/Node.hpp"
#include "../../include/LinkedList/LinkedList.hpp"
#include <iostream>

using namespace std;

int main(){
  LinkedList<Fish*> linkedList; //Buat linkedlist of fish pointer soalnya ga bisa langsung fish (krn abstract)
  Guppy *guppy = new Guppy(); //Buat guppy pointer soalnya dengan method "add", sama aja kayak
                                                  //Fish* f = new Guppy();
  guppy->setX(9);
  guppy->setY(10);
  linkedList.add(guppy); //add elmt 1
  guppy = nullptr;      //wajib jadiin nullptr
  delete guppy;

  guppy = new Guppy();
  guppy->setX(89);
  guppy->setY(100);

  linkedList.add(guppy); //add elmt2
  guppy = nullptr;
  delete guppy;

  guppy = new Guppy();
  guppy->setX(6);
  guppy->setY(100);

  linkedList.add(guppy); //add elmt 3
  guppy = nullptr;
delete guppy;
  Fish* f = linkedList.getIndex(0);
  if (f->getID() == 0){
    cout << "This is guppy!" << endl;
    Guppy *t = dynamic_cast<Guppy*>(linkedList.getIndex(2));
    cout << " " << t->getX() << endl;
  }
  return 0;
}
