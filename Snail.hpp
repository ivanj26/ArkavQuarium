#include "Global.hpp"
#include "Coin.hpp"

#ifndef SNAIL_HPP
#define SNAIL_HPP

class Snail{
    private:
        Location location;
        Coin* coin;     //Buat nyimpen koin(?) (MARK)
    public:
        Snail();
        /* KASUS I  = Kalau ada koin dia didekatnya, dia gerak ke lokasi koin
         * KASUS II = Kalau ga ada koin, dia diem
        */
        void Move(); 
};

#endif