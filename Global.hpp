#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define SPEED_COIN_FOOD     1
#define SPEED_FISH_NORMAL   2
#define SPEED_FISH_HUNGRY   3

struct Location{
    int x;
    int y;
};

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