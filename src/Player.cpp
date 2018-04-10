#include "../include/Player.hpp"
#include <string>

int Player::money = INIT_MONEY;
int Player::eggLevel = 0;

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

void Player::printMoney(){
  /* Print available money*/
  draw_text(std::to_string(money), 13, SCREEN_WIDTH - 75, 40, 80, 255, 35);
}
