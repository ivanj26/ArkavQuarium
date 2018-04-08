#include "../../include/Aquarium.hpp"
#include <iostream>
using namespace std;

Aquarium::Aquarium(){
	Fishes = new LinkedList<Fish>();
	Coins = new LinkedList<Coin>();
	Foods = new LinkedList<Food>();
	Guppy guppy();
	guppy.setX(generateRandom(40,SCREEN_WIDTH-40));
	guppy.setY(generateRandom(115,SCREEN_HEIGHT-40))
	guppy.setGrowLevel(1);
	guppy.setCoinTime(0);
	guppy.setNbFood(0);
	Fishes.add(guppy);
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
