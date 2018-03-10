#include "Global.hpp"

#ifndef COIN_HPP
#define COIN_HPP

class Coin{
    private:
        int intervalToGone;
        bool isReachBottom;  //Udah nyampe paling bawah atau ga?
        int value;          //berapa besar nilai koinnya
        Location location;
    public:
        Coin();
        void Move(); //Selalu move ke bawah

        /*Get & Set*/
        int getValue() const;
        void setValue(int);

        /*Get & Set Location*/
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);

        /*Get & Set intervalToGone*/
        void setIntervalToGone(int);
        int getIntervalToGone() const;

        /*Get & Set isReachBottom*/
        void setIsReachBottom(bool);
        bool getIsReachBottom(bool) const;
};

#endif
