#include "../../include/Animal/Piranha.hpp"
#include <math.h>
#include <iostream>

int main () {
	Piranha p1;
	cout << "spawn piranha1" << endl;
	p1.setEatLevelAt(3);
	cout << "set piranha1 eat level at by 3\n" << p1.getEatAtLevel() << endl;


	return 0;
}