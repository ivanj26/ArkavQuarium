#include "Fish.hpp"
#include "../Food/Food.hpp"
#include "../Coin/Coin.hpp"
#include "../LinkedList/Node.hpp"
#include "../LinkedList/LinkedList.hpp" //MARK lupa nambahin library

#ifndef GUPPY_HPP
#define GUPPY_HPP

class Guppy : public Fish{
    private:
        const int growTo2;
        const int growTo3;
        int growLevel;
        int nbFood; //udah makan berapa banyak
        const int intervalGenerateCoin;
        long coinTime;
    public:
        Guppy(); //default constructor untuk isi const growTo2 dan growTo3
        Guppy& operator=(const Guppy&);//4 sekawan, untuk operator assignment
        bool operator!=(const Guppy&);
        Coin generateCoin(); //override
        void printFish(string[], string[]);
        void Eat(Food); //overloading

        /*Get & Set*/
        void setNbFood(int);
        int getNbFood() const;

        /*Get & Set*/
        long getCoinTime();
        void setCoinTime(long); //MARK (ganti isi parameter resetCoinTime jadi setCoinTime)

        /*Get & Set*/
        int getGrowLevel() const;
        void setGrowLevel(int);

        void findNearestFoodOrFish(LinkedList<Food>&,double); //(MARK) Buat nyari makan
        /*Euclidean distance r = sqrt(x^2 + y^2)*/
};

#endif
