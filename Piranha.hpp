#include "Fish.hpp"
#include "Guppy.hpp"

#ifndef PIRANHA_HPP
#define PIRANHA_HPP

class Piranha : public Fish{
    private:
        
    public:
        Piranha();
        Coin generateCoin();    //Override dari class Fish
        void Eat(Guppy);        //Overloading dari class Fish

        Guppy findNearestFoodOrFish(); //(MARK) Buat nyari makan berupa object dari class Guppy
};

#endif