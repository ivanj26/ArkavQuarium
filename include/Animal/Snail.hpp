#include "../../include/Coin/Coin.hpp"
#include "../../main/oop.hpp"
#include "../LinkedList/Node.hpp"
#include "../LinkedList/LinkedList.hpp"

#ifndef SNAIL_HPP
#define SNAIL_HPP

class Snail {
    private:
        Location location;
        int amountCoin; //Banyaknya koin sekarang yang ditampung Snail
    public:
        Snail();
        Snail& operator=(const Snail&);//4 sekawan, untuk operator assignment
        void insertCoin(Coin);
        /* KASUS I  = Kalau ada koin dia didekatnya, dia gerak ke lokasi koin
         * KASUS II = Kalau ga ada koin, dia diem
        */
        void Move(double,double); 

        /*Get & Set*/
        void setX(int);
        int getX()const;
        void setY(int);
        int getY()const;

        /*Get & Set amountCoin*/
        void setAmountCoin(int);
        int getAmountCoin()const;
        void findNearestCoin(LinkedList<Coin>,double);
};
#endif
