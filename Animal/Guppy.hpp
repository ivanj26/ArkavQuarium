#include "Fish.hpp"
#include "../Food/Food.hpp"
#include "../Coin/Coin.hpp"

#ifndef GUPPY_HPP
#define GUPPY_HPP

class Guppy : public Fish{
    private:
        int growLevel;
        int nbFood; //udah makan berapa banyak
        const int intervalGenerateCoin;
    public:
        Guppy();
        Guppy& operator=(const Guppy&);//4 sekawan, untuk operator assignment
        Coin generateCoin(); //override
        void Eat(Food); //overloading

        /*Get & Set*/
        void setNbFood(int);
        int getNbFood() const;

        /*Get & Set*/
        int getGrowLevel() const;
        void setGrowLevel(int);

        Food findNearestFoodOrFish(); //(MARK) Buat nyari makan

};

#endif
