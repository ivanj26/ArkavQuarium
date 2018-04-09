#include "../Coin/Coin.hpp"
#include "../../main/oop.hpp"

#include <string>

#ifndef FISH_HPP
#define FISH_HPP

#define INTERVAL_TO_DIE 8000 //8000 ms
#define INTERVAL_FULL 10000 //10000 ms

using namespace std;

class Fish{
    private:
        int ID;
        int stateGambar;
        int directionTo;     // Lagi ngadep kemana
        Location location;
        bool isFull;            // Lagi kenyang(?)
        long hungerTime;
        const int intervalToDie;      // Batas waktu dia harus nyari makan
        const int intervalFull;       // Batas waktu dia kenyang berapa lama
    public:
        Fish();
        int getStateGambar();
        void setStateGambar(int);
        virtual Coin generateCoin() = 0; //Method Override, didefinisikan di class turunannya
        void Eat();             // Method Overloading, dia makannya makan apa(?) definisiin saat di class turunannya
        void Move(double,double);         // MARK perubahan tipe parameter

        /*Get & Set Location*/
        int getX()const;
        int getY()const;
        void setX(int);
        void setY(int);

        /*Get & Set isFull*/
        void setIsFull(bool);
        bool getIsFull() const;

        /*Get & Set LifeTime*/
        void setHungerTime(long);
        long getHungerTime();

        /*Get & set */
        void setID(int);
        int getID();

        /*get and set*/
        void setDirectionTo(int);
        int getDirectionTo();

        virtual void printFish(string[], string[]) = 0; //Print si ikan, ngadepnya ngikutin variable string directionTo
        void findNearestFoodOrFish(); //(MARK) Buat nyari makan, overloading
};

#endif
