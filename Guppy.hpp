#include "Fish.hpp"
#include "Food.hpp"

#ifndef GUPPY_HPP
#define GUPPY_HPP

class Guppy : public Fish{
    private:
        int growLevel;
        int nbFood; //udah makan berapa banyak
        const int intervalGenerateCoin;
    public:
        Guppy();
        Coin generateCoin(); //override
        void Eat(Food); //overloading

        /*Get & Set*/
        void setNbFood(int);
        int getNbFood();

        /*Get & Set*/
        int getGrowLevel();
        void setGrowLevel(int);

        Food findNearestFoodOrFish(); //BUat nyari makan

};

#endif