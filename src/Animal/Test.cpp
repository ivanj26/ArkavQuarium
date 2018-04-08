#include "../../include/Animal/Guppy.hpp"
#include "../../include/LinkedList/Node.hpp"
#include "../../include/LinkedList/LinkedList.hpp"
#include <iostream>

using namespace std;

int main(){
  LinkedList<Guppy*> linkedList;
  Guppy *guppy = new Guppy();
  guppy->setX(9);
  guppy->setY(10);

  linkedList.add(guppy);
  guppy = nullptr;
  delete guppy;

  guppy = new Guppy();
  guppy->setX(89);
  guppy->setY(100);

  linkedList.add(guppy);
  delete guppy;

  for (int i = 0; i < linkedList.getCurrentSize(); i++){
    Guppy u = *(linkedList.getIndex(i));
    cout << u.getX() << " " << u.getY() << endl;
  }
  // Guppy guppy;
  //
  // guppy.setX(25);
  // guppy.setY(70);
  //
  // fishes.add(guppy);
  return 0;
}
