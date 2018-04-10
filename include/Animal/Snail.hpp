#include "../../include/Coin/Coin.hpp"
#include "../../main/oop.hpp"
#include "../LinkedList/Node.hpp"
#include "../LinkedList/LinkedList.hpp"
#include <string>

#ifndef SNAIL_HPP
#define SNAIL_HPP

using namespace std;

class Snail {
    private:
        Location location;
        double timeDirection;
        double directionTo;
        int stateGambar;
        double amountCoin; //Banyaknya koin sekarang yang ditampung Snail
    public:
        Snail();
        Snail& operator=(const Snail&);//4 sekawan, untuk operator assignment
        void insertCoin(Coin);
        /* KASUS I  = Kalau ada koin dia didekatnya, dia gerak ke lokasi koin
         * KASUS II = Kalau ga ada koin, dia diem
        */
        void Move(double,double);
        void printSnail(string[]);
        /*Get & Set*/
        void setX(int);
        int getX()const;
        void setY(int);
        int getY()const;

        /*get & set */
        int getStateGambar();
        void setStateGambar(int);
        double getTimeDirection();
        void setTimeDirection(double);
        double getDirectionTo();
        void setDirectionTo(double);
        /*Get & Set amountCoin*/
        void setAmountCoin(double);
        double getAmountCoin()const;
        void findNearestCoin(LinkedList<Coin*>&,double);
};
#endif
