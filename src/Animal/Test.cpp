#include "../../include/Animal/Guppy.hpp"
#include "../LinkedList/Node.cpp"
#include "../LinkedList/LinkedList.cpp"
#include <iostream>

using namespace std;

int main(){
  LinkedList<Fish*> fishes;
  Fish *fish = new Guppy();
  fish->setX(90);
  fish->setY(100);

  fishes.add(fish);

  cout << "test" << endl;

  int x = fishes.find(fish);
  cout << x << endl;
  // Guppy guppy;
  //
  // guppy.setX(25);
  // guppy.setY(70);
  //
  // fishes.add(guppy);
  delete fish;
  return 0;
}
