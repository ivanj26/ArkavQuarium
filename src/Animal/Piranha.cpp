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

Coin* Piranha::generateCoin(){
  Coin* coin = NULL;
    coin = new Coin();
    coin->setValue(double(PRC_GUPPY * (eatAtLevel + 1)));
    coin->setX(getX());
    coin->setY(getY());
    coin->setStateGambar(0);
    eatAtLevel = -999;
  return coin;
}

void Piranha::printFish(string piranhaNormal[]){
  if (getIsFull() && (getDirectionTo() > 90 && getDirectionTo() < 270))
    draw_image(piranhaNormal[getStateGambar() + 10], getX(), getY());
  else if (getIsFull() && (getDirectionTo() <= 90 || getDirectionTo() >= 270))
    draw_image(piranhaNormal[getStateGambar() + 20], getX(), getY());
  else if (!getIsFull() && (getDirectionTo() > 90 && getDirectionTo() < 270))
    draw_image(piranhaNormal[getStateGambar() + 30], getX(), getY());
  else if (!getIsFull() && (getDirectionTo() <= 90 || getDirectionTo() >= 270))
    draw_image(piranhaNormal[getStateGambar() + 40], getX(), getY());

  if (getStateGambar() != 9)
    setStateGambar(getStateGambar() + 1);
  else
    setStateGambar(0);
}

void Piranha::Eat(Guppy g){
  eatAtLevel = g.getGrowLevel();
  setIsFull(true);
  setDirectionTo(-1);
  setHungerTime(INTERVAL_FULL);
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

  int j = 0;
  while (node->getValue()->getID() != 0){
    node = node->getNext();
    j++;
  }

  double tempMin = sqrt(pow(getX() - node->getValue()->getX(),2) + pow(getY() - node->getValue()->getY(),2));
  Node<Fish*> *minNode = node;

  if (tempMin <= 40){ //Makanan tepat di posisi piranha
    Guppy *guppy = dynamic_cast<Guppy*>(minNode->getValue());
    Eat(*guppy);
    fishes.remove(j);
  } else {
    int i = j+1;
    while (i < fishes.getCurrentSize() && node->getValue()->getID() != 0){
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

    Move(atan(deltaY / deltaX) * (180 / M_PI), deltatime * 1.5);
  }
}
