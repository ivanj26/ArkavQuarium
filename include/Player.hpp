#include "../include/Global.hpp"
#include "../main/oop.hpp"

class Player{
  private:
      static int money;
      static int eggLevel;
      static bool gameOver;
  public:
      static void setEggLevel(int);
      static int getEggLevel();
      static void setGameOver(bool);
      static bool isGameOver();
      static int getMoney();
      static void setMoney(int);
      static void printMoney();
};
