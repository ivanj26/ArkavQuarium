#include "../include/Player.hpp"
#include <string>

long Player::money = INIT_MONEY;
int Player::eggLevel = 0;

long Player::getMoney(){
  return money;
}

void Player::setMoney(long m){
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
