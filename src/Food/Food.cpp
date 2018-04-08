#include "..\..\include\Food"

Food::Food(int nx, int ny){
	this.location.x = nx;
	this.location.y = ny;
	this.isReachBottom = false;
}
Food::Food(location nl){
	this.location.x = nl.x;
	this.location.y = nl.y;
	this.isReachBottom = false;
}
Food& operator=(const Food& f){
	this.location.x = f.location.x;
	this.location.y = f.location.y;
	this.isReachBottom = f.isReachBottom;
}
void Move(){
	setY(getY()++);
}

int getX(){
	return this.location.x;
}

int getY(){
	return this.location.y;
}

void setX(int nx){
	this.location.x = nx;
}

void setY(int) {
	this.location.y = ny;
}

void setIsReachBottom(bool irb){
	this.isReachBottom = irb;
}

bool getIsReachBottom()const{
	return this.isReachBottom;
}
