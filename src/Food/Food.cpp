#include "../../include/Food/Food.hpp"

Food::Food(){
	stateGambar = 0;
	this->location.x = 40;
	this->location.y = 115;
	this->isReachBottom = false;
}

Food::Food(int nx, int ny){
	this->location.x = nx;
	this->location.y = ny;
	this->isReachBottom = false;
}

bool Food::operator!=(const Food& f){
	return location.x != f.location.x || location.y != f.location.y || isReachBottom != f.isReachBottom;
}

Food& Food::operator=(const Food& f){
	this->location.x = f.location.x;
	this->location.y = f.location.y;
	this->isReachBottom = f.isReachBottom;

	return *this;
}
void Food::Move(){
	if (location.x < SCREEN_HEIGHT - 40){
		setY(getY() + 1);
	}
}

int Food::getX(){
	return this->location.x;
}

int Food::getY(){
	return this->location.y;
}

void Food::setX(int nx){
	this->location.x = nx;
}

void Food::setY(int ny) {
	this->location.y = ny;
}

void Food::setIsReachBottom(bool irb){
	this->isReachBottom = irb;
}

bool Food::getIsReachBottom()const{
	return isReachBottom;
}

int Food::getStateGambar(){return stateGambar;}

void Food::setStateGambar(int i){
  stateGambar = i;
}

void Food::printFood(string foods[]){
	draw_image(foods[getStateGambar()], getX(), getY());
  if (getStateGambar() != 9)
    setStateGambar(getStateGambar() + 1);
  else
    setStateGambar(0);
}
