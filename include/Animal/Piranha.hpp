#include "Fish.hpp"
#include "Guppy.hpp"
#include "../Coin/Coin.hpp"
#include "../LinkedList/Node.hpp"
#include "../LinkedList/LinkedList.hpp" //MARK lupa nambahin library

#ifndef PIRANHA_HPP
#define PIRANHA_HPP

class Piranha : public Fish{
    private:
        /*Dia makan guppy level berapa di waktu ke-t
        * Kalau lagi kenyang/belum dapat guppy-nya di-set 999
        * Kalau udah makan guppy saat lapar di-set sesuai level Guppy yang dimakan, buat digunain pas generateCoin
        */
        int eatAtLevel;
    public:
        Piranha();
        Piranha& operator=(const Piranha&); //4 sekawan, untuk operator assignment
        Coin generateCoin();    //Override dari class Fish
        void Eat(Guppy);        //Overloading dari class Fish

        /*Get & Set eatGuppyAtLevel*/
        int getEatAtLevel()const;
        void setEatAtLevel(int);

        void findNearestFoodOrFish(LinkedList<Guppy>&); //(MARK) Buat nyari makan berupa object dari class Guppy
};

#endif
