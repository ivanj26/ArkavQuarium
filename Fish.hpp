#include "Global.hpp"
#include "Coin.hpp"
#include <string>

#ifndef FISH_HPP
#define FISH_HPP

#define INTERVAL_TO_DIE 8000 //8000 ms
#define INTERVAL_FULL 10000 //10000 ms

using namespace std;

class Fish{
    private:
        string directionTo;
        Location location;
        bool isFull;
        int intervalToDie; //deadline dia harus nyari makan
        int intervalFull; //dia kenyang berapa lama
    public:
        Fish();
        virtual Coin generateCoin() = 0; //override
        void Eat(); //overloading
        void Move(int); //param1 = konstanta MOVE

        /*Get & Set Location*/
        int getX();
        int getY();
        void setX(int);
        void setY(int);

        /*Get & Set isFull*/
        void setIsFull(bool);
        bool getIsFull();


        /*Get & Set Interval*/
        int getIntervalFull();
        void resetIntervalFull();
        int getIntervalToDie();
        void resetIntervalToDie();

        void printFish(); //ngikutin arah
        void findNearestFoodOrFish(); //Buat nyari makan, overloading
};

#endif