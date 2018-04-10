#include "../include/Global.hpp"
#include "../main/oop.hpp"

class Player{
  private:
      static int money;
      static int eggLevel;
  public:
      static void setEggLevel(int);
      static int getEggLevel();
      static int getMoney();
      static void setMoney(int);
      static void printMoney();
};
