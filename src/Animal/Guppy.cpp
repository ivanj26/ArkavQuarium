#include "../../include/Animal/Guppy.hpp"
#include "../../main/oop.hpp"
#include <math.h>

//Angka masih sembarang
Guppy::Guppy():growTo2(3), growTo3(10), intervalGenerateCoin(5000){
    growLevel = 0;
    nbFood = 0;
    coinTime = 0;
}

Guppy& Guppy::operator=(const Guppy& g){
    this->growLevel = g.growLevel;
    this->nbFood = g.nbFood;
    this->coinTime = g.coinTime;
    return *this;
}

void Guppy::printFish(){
  switch (growLevel) {
    case 1:
      draw_image(DIR_ICONS + "guppy_normal_1.png", generateRandom(40, SCREEN_WIDTH - 40), generateRandom(75 + 40, SCREEN_HEIGHT - 40));
    break;
    case 2:
      draw_image(DIR_ICONS + "guppy_normal_2.png", generateRandom(40, SCREEN_WIDTH - 40), generateRandom(75 + 40, SCREEN_HEIGHT - 40));
    break;
    case 3:
      draw_image(DIR_ICONS + "guppy_normal_3.png",generateRandom(40, SCREEN_WIDTH - 40), generateRandom(75 + 40, SCREEN_HEIGHT - 40));
    break;
  }
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
void Guppy::findNearestFoodOrFish(LinkedList<Food>& foods){
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

      Move(atan(deltaY / deltaX) * (180 / M_PI));
   }
}
