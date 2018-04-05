#include "Node.cpp"
#include <iostream>

using namespace std;

class Point{
  private:
    int x;
    int y;
  public:
    Point(int x, int y){
      this->x = x;
      this->y = y;
    }

    Point(){
      x = 0;
      y = 0;
    }

    int getX(){
      return x;
    }

    int getY(){
      return y;
    }
};

int main(){
  Node<Point> *node = new Node<Point>();
  Point p1(5,5);
  Point p2(9,10);

  //set & get Node class
  node->setValue(Point(3,4));
  cout << "This is node\n";
  cout << "X = " << node->getValue().getX() << endl;
  cout << "Y = " << node->getValue().getY() << endl;

  //setNext & getNext Node class
  Node<Point> *nextNode = new Node<Point>();
  Node<Point> *prevNode = new Node<Point>();
  nextNode->setValue(p1);
  prevNode->setValue(p2);

  node->setNext(nextNode);
  cout << "This is nextNode\n";
  cout << "X = " << node->getNext()->getValue().getX() << endl;
  cout << "Y = " << node->getNext()->getValue().getY() << endl;

  node->setPrev(prevNode);
  cout << "This is prevNode\n";
  cout << "X = " << node->getPrev()->getValue().getX() << endl;
  cout << "Y = " << node->getPrev()->getValue().getY() << endl;

  //Assignment operator
  node = nextNode;

  cout << "Current node after assign with nextNode\n";
  cout << "X = " << node->getValue().getX() << endl;
  cout << "Y = " << node->getValue().getY() << endl;

  //Cctor
  Node<Point>* otherNode = node;
  cout << "Call cctor!" << endl;
  cout << "X = " << otherNode->getValue().getX() << endl;
  cout << "Y = " << otherNode->getValue().getY() << endl;

  //dtor
  delete otherNode;
  delete prevNode;
  delete node;
  delete nextNode;
}
