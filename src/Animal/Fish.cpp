#include "../../include/Animal/Fish.hpp"
#include <math.h> //include fungsi draw_image

Fish::Fish():intervalToDie(INTERVAL_TO_DIE), intervalFull(INTERVAL_FULL){
  isFull = true;
  hungerTime = INTERVAL_FULL;
  // location.x = random
  // location.y = random
}
void Fish::Eat(){}
void Fish::Move(double degree, double deltatime){
    //Belum dikali waktu
	  /*Spek gambar :
     * Ada menu bar yang tingginya 75px, maka batas bawah height jadi 75+40 = 115 (40 nilai tengah tinggi guppy), batas atas : SCREEN_HEIGHT- 40
     * sedangkan batas bawah lebar hanya nilai tengah guppy jadinya 40px, batas atas sama nilainya seperti batas atas tinggi*/

    bool isInsideX = ((location.x + int(SPEED_FISH_NORMAL * deltatime * cos(degree * (M_PI / 180)))) <= SCREEN_WIDTH - 40) && ((location.x + int(SPEED_FISH_NORMAL * deltatime * cos(degree * (M_PI / 180)))) >= 40);
    bool isInsideY = ((location.y + int(SPEED_FISH_NORMAL * deltatime * sin(degree * (M_PI / 180)))) <= SCREEN_HEIGHT - 40) && ((location.y + int(SPEED_FISH_NORMAL * deltatime * sin(degree * (M_PI / 180)))) >= 115);

    while (!(isInsideX && isInsideY)){
      //Cari arah baru kalau lewatin batas bawah atau atasnya
      degree = generateRandom(0,360);
      isInsideX = ((location.x + int(SPEED_FISH_NORMAL * deltatime * cos(degree * (M_PI / 180)))) <= SCREEN_WIDTH - 40) && ((location.x + int(SPEED_FISH_NORMAL * deltatime * cos(degree * (M_PI / 180)))) >= 40);
      isInsideY = ((location.y + int(SPEED_FISH_NORMAL * deltatime * sin(degree * (M_PI / 180)))) <= SCREEN_HEIGHT - 40) && ((location.y + int(SPEED_FISH_NORMAL * deltatime * sin(degree * (M_PI / 180)))) >= 115);
    }

    location.x += int(SPEED_FISH_NORMAL * deltatime * cos(degree * (M_PI / 180)));
    location.y += int(SPEED_FISH_NORMAL * deltatime * sin(degree * (M_PI / 180)));
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

int Fish::getDirectionTo(){
  return directionTo;
}

void Fish::findNearestFoodOrFish(){}
