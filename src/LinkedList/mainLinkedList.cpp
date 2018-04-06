#include "LinkedList.cpp"
#include "Node.cpp"
#include <iostream>

using namespace std;

int main(){
  int a = 1;
  int b = 2;
  int c = 3;

  LinkedList<int> *linkedList = new LinkedList<int>();
  linkedList->add(a);
  linkedList->add(b);
  linkedList->add(c);

  cout << "A = " << linkedList->getHead()->getValue() << endl;
  cout << "B = " << linkedList->getHead()->getNext()->getValue() << endl;
  cout << "index C = " << linkedList->find(c) << endl;

  linkedList->remove(b);
  cout << "Size of linkedList = " << linkedList->getCurrentSize() << endl;

  linkedList->add(a);
  linkedList->add(c);
  linkedList->add(c);
  linkedList->add(b);
  linkedList->remove(c);
  Node<int> *node = linkedList->getHead();
  for (int i = 0; i < linkedList->getCurrentSize(); i++){
    cout << "Element ke-" << i << " = " << node->getValue() << endl;
    node = node->getNext();
  }


  delete node;
  delete linkedList;
}
