#include "../Global.hpp"
#include "../../main/oop.hpp"
#include <string>

#ifndef FOOD_HPP
#define FOOD_HPP

using namespace std;
class Food{
    private:
        Location location;
        int stateGambar;
        bool isReachBottom;  //Udah nyampe paling bawah atau ga?
    public:
        Food();
        /*get & set */
        int getStateGambar();
        void setStateGambar(int);
        void printFood(string[]);
        Food(int, int);
        bool operator!=(const Food&);
        Food& operator=(const Food&); //4 sekawan, utk operator assignment
        void Move(double); //Move selalu ke bawah, SPEED_FOOD < SPEED_FISH_NORMAL

        /*Get & Set Location*/
        int getX();
        int getY();
        void setX(int);
        void setY(int);

        /*Get & Set isReachBottom*/
        void setIsReachBottom(bool);
        bool getIsReachBottom()const;
};

#endif
