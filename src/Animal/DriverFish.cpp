#include "../../include/Animal/Fish.hpp"
#include <iostream>

int main () {
	Fish f1;
	cout << "> spawn fish1" << endl;
	f1.setTimeDirection(2.0);
	cout << "set fish time direction by 2 \n" << "> fish1 time direction : " << f1.getTimeDirection() << endl;
	cout << "> initial state : " << f1.getStateGambar();
	f1.setDirectionTo(90.0);
	cout << "set fish1 direction by 90 \n" << "> fish1 direction : "<< f1.getDirectionTo() << endl;
	f1.setID(1);
	cout << "set fish1 ID by 1 \n" << "> fish1 ID : " << f1.getID();
	cout << "fish1 location\n" << "> x : " << f1.getX() << "\n> y : " << f1.getY() << endl;

	return 0;
}