#include "Global.hpp"

#ifndef COIN_HPP
#define COIN_HPP

class Coin{
    private:
        int value; //berapa besar
        Location location;
    public:
        Coin();
        void Move(); //move ke bawah

        /*Get & Set*/
        int getValue();
        void setValue(int);
};

#endif