#include "../Global.hpp"

#ifndef COIN_HPP
#define COIN_HPP

class Coin{
    private:
        int value;          //berapa besar nilai koinnya
        Location location;
    public:
        Coin();
        Coin& operator=(const Coin&);//4 sekawan, untuk operator assignment
        void Move(); //Selalu move ke bawah

        /*Get & Set*/
        int getValue() const;
        void setValue(int);

        /*Get & Set Location*/
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
};

#endif
