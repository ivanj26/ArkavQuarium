#include "../../include/Animal/Fish.hpp"
#include "../../main/oop.hpp"
#include <math.h> //include fungsi draw_image

Fish::Fish():intervalToDie(INTERVAL_TO_DIE), intervalFull(INTERVAL_FULL){
  isFull = true;
  hungerTime = INTERVAL_FULL;
  // location.x = random
  // location.y = random
}
void Fish::Eat(){}
void Fish::Move(double degree){
    //Belum dikali waktu
	  //MARK -> ukuran guppy (pjg dan lebar) belum tau, harus ada koreksi nilai lagi
    if ((location.x += (SPEED_FISH_NORMAL *  ((int)cos(degree * (M_PI / 180))))) > SCREEN_WIDTH){
      location.x = SCREEN_WIDTH;
    }

    if ((location.y += (SPEED_FISH_NORMAL *  ((int)sin(degree * (M_PI / 180))))) > SCREEN_HEIGHT){
      location.y = SCREEN_HEIGHT;
    }
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
    draw_image("../../main/ikan.png", location.x, location.y);
}

void Fish::findNearestFoodOrFish(){}
