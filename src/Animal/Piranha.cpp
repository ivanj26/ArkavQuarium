#include "../../include/Animal/Piranha.hpp"
#include "../../main/oop.hpp"
#include <math.h>

Piranha::Piranha(){
  eatAtLevel = -999;
}

Piranha& Piranha::operator=(const Piranha& p){
  this->eatAtLevel = p.eatAtLevel;
  return *this;
}

Coin Piranha::generateCoin(){
  Coin coin;
  if (eatAtLevel != -999){
    coin.setValue(PRC_FISH * (eatAtLevel + 1));
    coin.setX(getX());
    coin.setY(getY());
    eatAtLevel = -999;
  } else {
    coin.setValue(0);
  }
  return coin;
}

void Piranha::printFish(){
  //belum didefinisikan soalnya belum ada gambarnya
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

void Piranha::findNearestFoodOrFish(LinkedList<Guppy>& guppies){
  Node<Guppy>* node = guppies.getHead();
  double tempMin = sqrt(pow(getX() - node->getValue().getX(),2) + pow(getY() - node->getValue().getY(),2));

  if (tempMin == 0){ //Makanan tepat di posisi piranha
    Eat(node->getValue());
    guppies.remove(node->getValue());
  } else {
    int i = 1;
    Node<Guppy> *minNode = guppies.getHead();

    while (tempMin != 0 && i < guppies.getCurrentSize()){
      node = node->getNext();
      double temp = sqrt(pow(getX() - node->getValue().getX(),2) + pow(getY() - node->getValue().getY(),2));
      if (tempMin >  temp){
        tempMin = temp;
        minNode = node;
      }
      i++;
    }

    //Bergerak ke arah makanan terdekat
    int deltaY = getY() - minNode->getValue().getY();
    int deltaX = getX() - minNode->getValue().getX();

    Move(atan(deltaY / deltaX) * (180 / M_PI));
  }
}
