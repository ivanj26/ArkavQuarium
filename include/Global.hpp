#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define SPEED_COIN_FOOD     1
#define SPEED_FISH_NORMAL   2
#define PRC_FISH 150
#define INIT_MONEY 500

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
