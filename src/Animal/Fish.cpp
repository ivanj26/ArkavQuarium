#include "../../include/Animal/Fish.hpp"
#include "../../main/oop.hpp"
#include <math.h> //include fungsi draw_image

void Fish::Fish():intervalToDie(INTERVAL_TO_DIE), intervalFull(INTERVAL_FULL){}
void Fish::Eat(){}
void Fish::Move(int degree){
    location.x += (SPEED_FISH_NORMAL * cos(degree * (M_PI / 180)));
    location.y += (SPEED_FISH_NORMAL * sin(degree * (M_PI / 180))); 
}

int Fish::getX() const{
    return location.x;
}

int Fish::getY() const{
    return location.y;
}

void Fish::setX(int x){
    location.x = x;
}

void Fish::setY(int y){
    location.y = y;
}

void Fish::setIsFull(bool isFull){
    this->isFull = isFull;
}

bool Fish::getIsFull() const{
    return isFull;
}

void Fish::setHungerTime(long hungerTime){
    this->hungerTime = hungerTime;
}

long Fish::getHungerTime(){
    return hungerTime;
}

void Fish::printFish(){
    //Lokasi gambar masih sembarang
    draw_image("../main/ikan.png", location.x, location.y);
}

void Fish::findNearestFoodOrFish(){}
