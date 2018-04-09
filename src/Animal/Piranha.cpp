#include "../../include/Animal/Piranha.hpp"
#include "../../main/oop.hpp"
#include <math.h>

Piranha::Piranha(){
  eatAtLevel = -999;
  setID(1);
}

Piranha& Piranha::operator=(const Piranha& p){
  this->eatAtLevel = p.eatAtLevel;
  return *this;
}

Coin Piranha::generateCoin(){
  Coin coin;
  if (eatAtLevel != -999){
    coin.setValue(PRC_GUPPY * (eatAtLevel + 1));
    coin.setX(getX());
    coin.setY(getY());
    eatAtLevel = -999;
  } else {
    coin.setValue(0);
  }
  return coin;
}

void Piranha::printFish(string piranhaNormal[], string piranhaHungry[]){
  if (getIsFull())
    draw_image(piranhaNormal[getStateGambar()], getX(), getY());
  else
    draw_image(piranhaHungry[getStateGambar()], getX(), getY());

  if (getStateGambar() != 9)
    setStateGambar(getStateGambar() + 1);
  else
    setStateGambar(0);
}

void Piranha::Eat(Guppy g){
  eatAtLevel = g.getGrowLevel();
}

/*Get & Set eatGuppyAtLevel*/
int Piranha::getEatAtLevel()const{
  return eatAtLevel;
}

void Piranha::setEatAtLevel(int eatAtLevel){
  this->eatAtLevel = eatAtLevel;
}

void Piranha::findNearestFoodOrFish(LinkedList<Fish*>& fishes, double deltatime){
  Node<Fish*>* node = fishes.getHead();

  while (node->getValue()->getID() != 0){
    node = node->getNext();
  }

  double tempMin = sqrt(pow(getX() - node->getValue()->getX(),2) + pow(getY() - node->getValue()->getY(),2));
  Node<Fish*> *minNode = node;

  if (tempMin == 0){ //Makanan tepat di posisi piranha
    Guppy *guppy = dynamic_cast<Guppy*>(minNode->getValue());
    Eat(*guppy);
    fishes.remove(minNode->getValue());
  } else {
    int i = 1;
    while (tempMin != 0 && i < fishes.getCurrentSize() && node->getValue()->getID() != 0){
      node = node->getNext();
      double temp = sqrt(pow(getX() - node->getValue()->getX(),2) + pow(getY() - node->getValue()->getY(),2));
      if (tempMin >  temp){
        tempMin = temp;
        minNode = node;
      }
      i++;
    }

    //Bergerak ke arah makanan terdekat
    int deltaY = getY() - minNode->getValue()->getY();
    int deltaX = getX() - minNode->getValue()->getX();

    Move(atan(deltaY / deltaX) * (180 / M_PI), deltatime);
  }
}
