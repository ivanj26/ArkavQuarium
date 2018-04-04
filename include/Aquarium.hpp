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
        const int max_X;
        const int max_Y;
        LinkedList<Fish> Fishes;
        Snail snail;
        LinkedList<Coin> Coins;
        LinkedList<Food> Foods;
    public:
        Aquarium();
        Snail getSnail();
        LinkedList<Fish> getFishes();
        LinkedList<Coin> getCoins();
        LinkedList<Food> getFoods();
        void showAquarium(); //Gambarin aquarium dari linkedlist2 yang ada
        /*showAquarium : 0 <= x <= max_x dan 0 <= y <= max_y*/
};

#endif
