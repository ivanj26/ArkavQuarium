#include "../include/Aquarium.hpp"
#include "../main/oop.hpp"
#include <iostream>

Aquarium::Aquarium(){
	this->max_X= SCREEN_WIDTH;
	this->max_Y= SCREEN_HEIGHT;
}

Aquarium::Aquarium(int x , int y){
	this->max_X = x;
	this->max_Y = y;
}

Snail Aquarium::getSnail(){
	return this->snail;
}

LinkedList<Fish> Aquairum::getFishes(){
	return this->Fishes;
}


LinkedList<Fish> Aquarium::getCoins(){
	return this->Coins;
}


LinkedList<Fish> Aquarium::getFoods(){
	return this->Foods;
}

void Aquarium::showAquarium(){
	
}