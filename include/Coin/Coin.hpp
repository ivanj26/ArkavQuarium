#include "../Global.hpp"
#include "../../main/oop.hpp"
#include <string>
using namespace std;

#ifndef COIN_HPP
#define COIN_HPP

class Coin{
    private:
        int stateGambar;
        long value;          //berapa besar nilai koinnya
        Location location;
    public:
        Coin();
        bool operator!=(const Coin&);
        Coin& operator=(const Coin&);//4 sekawan, untuk operator assignment
        void Move(double deltatime); //Selalu move ke bawah

        /*Get & Set*/
        long getValue() const;
        void setValue(long);
        void printCoin(string[]);
        int getStateGambar();
        void setStateGambar(int);

        /*Get & Set Location*/
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
};

#endif
