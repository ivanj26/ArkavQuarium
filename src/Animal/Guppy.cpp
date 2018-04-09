#include "../../include/Animal/Guppy.hpp"
#include "../../main/oop.hpp"
#include <math.h>

//Angka masih sembarang
Guppy::Guppy():growTo2(3), growTo3(10), intervalGenerateCoin(5000){
    growLevel = 1;
    nbFood = 0;
    coinTime = 0;
    setID(0);
}

Guppy& Guppy::operator=(const Guppy& g){
    this->growLevel = g.growLevel;
    this->nbFood = g.nbFood;
    this->coinTime = g.coinTime;
    return *this;
}

bool Guppy::operator!=(const Guppy& g){
  return g.getX() != getX() || g.getY() != getY() || growLevel != g.growLevel || g.coinTime != coinTime || g.nbFood != nbFood;
}

void Guppy::printFish(string guppyNormal[], string guppyHungry[]){
    if (getIsFull())
      draw_image(guppyNormal[getStateGambar() + ((growLevel - 1) * 9)], getX(), getY());
    else
      draw_image(guppyHungry[getStateGambar() + ((growLevel - 1) * 9)], getX(), getY());

    if (getStateGambar() != 9)
      setStateGambar(getStateGambar() + 1);
    else
      setStateGambar(0);
}

Coin Guppy::generateCoin(){
    Coin coin;
    coin.setY(getY());
    coin.setX(getX());
    switch(growLevel){
        case 1: //Level 1
            coin.setValue(0);
        break;
        case 2: //Level 2
            coin.setValue(100);
        break;
        default: //Level 3
            coin.setValue(200);
    }

    setCoinTime(0);
    return coin;
}

void Guppy::Eat(Food food){
    if (!food.getIsReachBottom()){
        nbFood++;

        if (nbFood == growTo2){
          growLevel++;
        } else if (nbFood == growTo3){
          growLevel++;
        }

        setHungerTime(0);
    }
}

void Guppy::setNbFood(int nbFood){
    this->nbFood = nbFood;
}

int Guppy::getNbFood()const{
    return nbFood;
}

void Guppy::setCoinTime(long coinTime){
    this->coinTime = coinTime;
}

long Guppy::getCoinTime(){
    return coinTime;
}

int Guppy::getGrowLevel()const{
    return growLevel;
}

void Guppy::setGrowLevel(int growLevel){
    this->growLevel = growLevel;
}


/* Asumsi : Kondisi sedang lapar*/
void Guppy::findNearestFoodOrFish(LinkedList<Food>& foods, double deltaTime){
  /*Jarak euclidean          = sqrt((x2-x1)^2 + (y2-y1)^2)*/
  /*Bergerak ke arah makanan = arctan(delta y / delta x)*/
  Node<Food> *node = foods.getHead();
  double tempMin = sqrt(pow(getX() - node->getValue().getX(),2) + pow(getY() - node->getValue().getY(),2));

  if (tempMin == 0){ //Makanan tepat di posisi guppy
    Eat(node->getValue());
    foods.remove(node->getValue());
  } else {
      int i = 1;
      Node<Food> *minNode = foods.getHead();

      while (tempMin != 0 && i < foods.getCurrentSize()){
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

      Move(atan(deltaY / deltaX) * (180 / M_PI), deltaTime);
   }
}
