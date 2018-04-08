#include "../Global.hpp"

#ifndef FOOD_HPP
#define FOOD_HPP

class Food{
    private:
        Location location;
        bool isReachBottom;  //Udah nyampe paling bawah atau ga?
    public:
        Food();
        Food(int, int);
        bool operator!=(const Food&);
        Food& operator=(const Food&); //4 sekawan, utk operator assignment
        void Move(); //Move selalu ke bawah, SPEED_FOOD < SPEED_FISH_NORMAL

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
