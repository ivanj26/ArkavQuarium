#include "../../include/Aquarium.hpp"
#include "../../main/oop.hpp"
#include "../../include/LinkedList/Node.hpp"
#include "../../include/Animal/Fish.hpp"
#include "../../include/Animal/Snail.hpp"
#include "../../include/Animal/Guppy.hpp"
#include <iostream>
using namespace std;

Aquarium::Aquarium():snail(){
	Fishes = new LinkedList<Fish>();
	Coins = new LinkedList<Coin>();
	Foods = new LinkedList<Food>();
}

Aquarium::Aquarium(int x , int y):snail(){
	Fishes = new LinkedList<Fish>();
	Coins = new LinkedList<Coin>();
	Foods = new LinkedList<Food>();
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
