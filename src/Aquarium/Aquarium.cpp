#include "../../include/Aquarium.hpp"
#include "../../include/Animal/Guppy.hpp"
#include "../../include/Animal/Piranha.hpp"
#include "../../include/Animal/Snail.hpp"
#include "../../include/LinkedList/Node.hpp"
#include "../../include/LinkedList/LinkedList.hpp"
#include "../../include/Aquarium.hpp"
#include <iostream>
using namespace std;

Aquarium::Aquarium():snail(){
	//Menginisiasi Guppy dan insert ke LinkedList of Guppy
	Guppy *guppy= new Guppy();
	guppy->setX(generateRandom(40,SCREEN_WIDTH-40));
	guppy->setY(generateRandom(115,SCREEN_HEIGHT-40));
	Fishes.add(guppy);
	guppy = nullptr;
	delete guppy;

	SDL_Delay(1000);
	guppy = new Guppy();
	guppy->setX(generateRandom(40,SCREEN_WIDTH-40));
	guppy->setY(generateRandom(115,SCREEN_HEIGHT-40));
	Fishes.add(guppy);
	guppy = nullptr;
	delete guppy;
}

Snail& Aquarium::getSnail(){
	return this->snail;
}

LinkedList<Fish*>& Aquarium::getFishes(){
	return this->Fishes;
}

LinkedList<Coin>& Aquarium::getCoins(){
	return this->Coins;
}

LinkedList<Food>& Aquarium::getFoods(){
	return this->Foods;
}
