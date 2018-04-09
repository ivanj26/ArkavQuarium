#include "Animal/Fish.hpp"
#include "Animal/Guppy.hpp"
#include "Animal/Piranha.hpp"
#include "Animal/Snail.hpp"
#include "Coin/Coin.hpp"
#include "Food/Food.hpp"
#include "LinkedList/LinkedList.hpp"
#include "Global.hpp"

#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

class Aquarium{
    private:
        LinkedList<Fish*> Fishes;
        Snail snail;
        LinkedList<Coin*> Coins;
        LinkedList<Food*> Foods;
    public:
        Aquarium();
        Snail getSnail();
        LinkedList<Fish*> getFishes();
        LinkedList<Coin*> getCoins();
        LinkedList<Food*> getFoods();
};

#endif
