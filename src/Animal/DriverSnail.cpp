#include "../../include/Animal/Snail.hpp"

int main () {
	Snail s1;
	cout << "spawn snail1" << endl;
	s1.setX(80);
	s1.setY(80);
	cout << "set snail1 position by (80, 80)\n" << "> x : " << s1.getX() << "\n> y : "<< s1.getY() << endl;
	s1.setAmountCoin(10);
	cout << "set snail1 amount coin by 10\n" << "> snail1 amount coin : " << s1.getAmountCoin() << endl;
	s1.setTimeDirection(1000.0);
	cout << "set snail1 time direction by 1000\n" << "> snail1 time direction : " << s1.getTimeDirection() << endl;
	return 0;
}