#include "../../include/Aquarium.hpp"
#include <iostream>
using namespace std;

Aquarium::Aquarium(){
	//Menginisiasi Guppy dan insert ke LinkedList of Guppy
	Guppy guppy;
	guppy.setX(generateRandom(40,SCREEN_WIDTH-40));
	guppy.setY(generateRandom(115,SCREEN_HEIGHT-40));
	guppy.setGrowLevel(1);
	guppy.setCoinTime(0);
	guppy.setNbFood(0);
	Guppies.add(guppy);
	//Menginisiasi Piranha
	Piranha piranha;

}

Snail Aquarium::getSnail(){
	return this->snail;
}

LinkedList<Guppy> Aquarium::getGuppies(){
	return this->Guppies;
}

LinkedList<Coin> Aquarium::getCoins(){
	return this->Coins;
}

LinkedList<Food> Aquarium::getFoods(){
	return this->Foods;
}
