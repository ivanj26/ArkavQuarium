#include "../../include/Coin/Coin.hpp"

Coin::Coin(){
	location.x = 0;
	location.y = 0;
	value = 0;
	stateGambar = 0;
}

bool Coin::operator!=(const Coin& c){
	return location.x != c.location.x || location.y != c.location.y || value != c.value;
}

Coin& Coin::operator=(const Coin& T){//4 sekawan, untuk operator assignment
	this->value = T.value;
	this->location.x = T.location.x;
	this->location.y = T.location.y;
	return *this;
}
void Coin::Move(double deltatime){
	//MARK -> ukuran coin belum tau, harus ada koreksi nilai lagi
	bool isInsideY = ((location.y + int(SPEED_COIN_FOOD * deltatime * sin(M_PI / 180))) < SCREEN_HEIGHT - 40);

	if (isInsideY){
		location.y += 1;
	}
} //Selalu move ke bawah

/*Get & Set*/
int Coin::getValue() const{
	return value;
}

void Coin::setValue(int val){
	value = val;
}

/*Get & Set Location*/
int Coin::getX() const{
	return location.x;
}
int Coin::getY() const{
	return location.y;
}

void Coin::setX(int x){
	location.x = x;
}
void Coin::setY(int y){
	location.y = y;
}

void Coin::printCoin(string coins[]){
	if (value == SILVER)
    draw_image(coins[getStateGambar()], getX(), getY());
  else if (value == GOLD)
    draw_image(coins[getStateGambar()+10], getX(), getY());

  if (getStateGambar() != 9)
    setStateGambar(getStateGambar() + 1);
  else
    setStateGambar(0);
}

int Coin::getStateGambar(){return stateGambar;}
void Coin::setStateGambar(int i){
  stateGambar = i;
}
