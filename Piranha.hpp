#include "Fish.hpp"
#include "Guppy.hpp"

#ifndef PIRANHA_HPP
#define PIRANHA_HPP

class Piranha : public Fish{
    private:
        
    public:
        Piranha();
        Coin generateCoin(); //override
        void Eat(Guppy); //overloading

        Guppy findNearestFoodOrFish(); //BUat nyari makan
};

#endif