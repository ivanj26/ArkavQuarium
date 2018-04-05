#include "../../include/Animal/Guppy.hpp"

//Angka masih sembarang
void Guppy::Guppy():growTo2(3), growTo2(10), intervalGenerate(5000){
    growLevel = 0;
    nbFood = 0;
    coinTime = 0;
}

Guppy& Guppy::operator=(const Guppy& g){
    Guppy guppy = g;
    return guppy;
}


/*Check lagi!*/
Coin Guppy::generateCoin(){
    Coin coin;
    switch(growLevel){
        case 1: //Level 1
            coin.setValue(100);
            coin.setX(location.x);
            coin.setY(location.y);
        break;
        case 2: //Level 2
            coin.setValue(200);
            coin.setY(location.y);
            coin.setX(location.x);
        break;
        default: //Level 3
            coin.setValue(300);
            coin.setX(location.x);
            coin.setY(location.y);
    }
}

void Guppy::Eat(Food food){
    if (!food.getIsReachBottom()){
        nbFood++;
    }
}

void Guppy::setNbFood(int nbFood){
    this->nbFood = nbFood;
}

int Guppy::getNbFood()const{
    return nbFood;
}

void Guppy::resetCoinTime(){
    coinTime = 0;
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

void findNearestFoodOrFish(LinkedList<Food> foods){
    
}
