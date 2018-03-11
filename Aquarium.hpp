#include "Animal/Fish.hpp"
#include "Animal/Guppy.hpp"
#include "Animal/Piranha.hpp"
#include "Animal/Snail.hpp"
#include "Coin/Coin.hpp"
#include "Food/Food.hpp"
#include "LinkedList.hpp"

#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

class Aquarium{
    private:
        LinkedList<Fish> Fishes;
        LinkedList<Snail> Snails;
        LinkedList<Coin> Coins;
        LinkedList<Food> Foods;
    public:
        Aquarium();
        void showAquarium(); //Gambarin aquarium dari linkedlist2 yang ada
};

#endif