#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define SPEED_COIN_FOOD     1
#define SPEED_FISH_NORMAL   2
#define SPEED_FISH_HUNGRY   3

/*  Tipe bentukan Location :
 *  1. x = absis
 *  2. y = ordinat
 *  Catatan : makin kebawah y++, makin ke kanan x++
*/

struct Location{
    int x;
    int y;
};

/* Penjelasan konstanta MOVE :  
 *  1. N = NORTH, value = 0;
 *  2. S = SOUTH, value = 1;
 *  3. W = WEST, value = 2;
 *  4. dst sampai 8 mata angin
*/

enum MOVE{
    MOVE_N,
    MOVE_S,
    MOVE_W,
    MOVE_E,
    MOVE_NE,
    MOVE_SE,
    MOVE_SW,
    MOVE_NW
};

#endif