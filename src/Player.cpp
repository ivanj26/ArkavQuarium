#include "../include/Player.hpp"
#include <string>

int Player::money = INIT_MONEY;
int Player::eggLevel = 0;
bool Player::gameOver = false;

int Player::getMoney(){
  return money;
}

void Player::setMoney(int m){
  money = m;
}

int Player::getEggLevel(){
  return eggLevel;
}

void Player::setEggLevel(int el){
  eggLevel = el;
}

bool Player::isGameOver(){
  return gameOver;
}

void Player::setGameOver(bool go){
  gameOver = go;
}

void Player::printMoney(){
  /* Print available money*/
  draw_text(std::to_string(money), 13, SCREEN_WIDTH - 75, 40, 80, 255, 35);
}
