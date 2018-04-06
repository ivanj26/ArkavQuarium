#include "../../include/Coin/Coin.hpp"

Coin::Coin(){
	value = 0;
}

Coin& Coin::operator=(const Coin& T){//4 sekawan, untuk operator assignment
	this->value = T.value;
	this->location.x = T.location.x;
	this->location.y = T.location.y;
	return *this;
}
void Coin::Move(){
	//MARK -> ukuran coin belum tau, harus ada koreksi nilai lagi
	if (location.y < SCREEN_HEIGHT){
		location.y++;
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
