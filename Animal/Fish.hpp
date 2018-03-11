#include "../Global.hpp"
#include "../Coin/Coin.hpp"

#include <string>


#ifndef FISH_HPP
#define FISH_HPP

#define INTERVAL_TO_DIE 8000 //8000 ms
#define INTERVAL_FULL 10000 //10000 ms

using namespace std;

class Fish{
    private:
        string directionTo;     // Lagi ngadep kemana
        Location location;
        bool isFull;            // Lagi kenyang(?)
        int intervalToDie;      // Batas waktu dia harus nyari makan
        int intervalFull;       // Batas waktu dia kenyang berapa lama
    public:
        Fish();
        virtual Coin generateCoin() = 0; //Method Override, didefinisikan di class turunannya
        void Eat();             // Method Overloading, dia makannya makan apa(?) definisiin saat di class turunannya
        void Move(int);         // param1 = konstanta MOVE atau directionnya

        /*Get & Set Location*/
        int getX()const;
        int getY()const;
        void setX(int);
        void setY(int);

        /*Get & Set isFull*/
        void setIsFull(bool);
        bool getIsFull() const;


        /*Get & Set Interval*/
        int getIntervalFull() const;
        void resetIntervalFull();
        int getIntervalToDie() const;
        void resetIntervalToDie();

        void printFish();             //Print si ikan, ngadepnya ngikutin variable string directionTo
        void findNearestFoodOrFish(); //(MARK) Buat nyari makan, overloading
};

#endif