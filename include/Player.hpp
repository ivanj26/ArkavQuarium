#include "../include/Global.hpp"
#include "../main/oop.hpp"

class Player{
  private:
      static long money;
      static int eggLevel;
  public:
      static void setEggLevel(int);
      static int getEggLevel();
      static long getMoney();
      static void setMoney(long);
      static void printMoney();
};
