#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define INTERVAL_TIME_DIRECTION 2000
#define SPEED_COIN_FOOD     80
#define SPEED_FISH_NORMAL   87
#define SPEED_SNAIL         60
#define SILVER 35
#define GOLD 55
#define PRC_GUPPY 100
#define PRC_EGG_1 3000
#define PRC_EGG_2 4000
#define PRC_EGG_3 5000
#define PRC_FOOD 5
#define PRC_PIRANHA 1000
#define INIT_MONEY 200

// Pengaturan ukuran layar yang dihasilkan.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*  Tipe bentukan Location :
 *  1. x = absis
 *  2. y = ordinat
 *  Catatan : makin kebawah y++, makin ke kanan x++
*/
struct Location{
    int x;
    int y;
};

#endif
