#include "../../include/Animal/Guppy.hpp"
#include <iostream>
#include <math.h>


int main () {
	Guppy g1;
	cout << "spawn guppy1" << endl;
	g1.setNbFood(5);
	cout << "set guppy1 food by 5\n" << "> guppy1 food : " << g1.getNbFood() << endl;
	g1.setCoinTime(1000);
	cout << "set guppy1 coin time by 1000\n" << "> guppy1 coin time : " << g1.getCoinTime() << endl;
	cout << "> guppy1 grow level : " << g1.getGrowLevel() << endl;

	return 0;
}