#include "oop.hpp"
#include <math.h>
#include "../src/LinkedList/LinkedList.cpp"
#include "../src/LinkedList/Node.cpp"
#include "../include/Global.hpp"
#include "../src/Player.cpp"
#include <string.h>

using namespace std;

const double speed = 50; // pixels per second

void updateAll(double now, int deltatime, bool (&unlockFish)[7], int (&x) [7]){
  clear_screen();
  /* Draw aquarium & menu_bar to screen*/
  draw_image(DIR_ICONS + "aquarium2.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  draw_image(DIR_ICONS + "menubar.gif" , SCREEN_WIDTH / 2, 75 / 2);

  /* Print player's money,etc*/
  Player::printMoney();


  /*Unlock fish (menu bar)*/
  for (int i = 0; i < 7; i++){
    if (unlockFish[i] == true){
      draw_image(DIR_ICONS + "mbuttonu.gif", x[i], 25);
      switch(i){
        case 0:
          draw_image(DIR_ICONS + "guppy_normal_1.png", x[i] , 25);
          draw_text("$" + to_string(PRC_GUPPY), 12, x[i] - 10, 45, 80, 255, 25);
          break;
        case 1:
          draw_image(DIR_ICONS + "piranha.png", x[i], 25);
          draw_text("$" + to_string(PRC_PIRANHA), 12, x[i] - 10, 45, 80, 255, 35);
          break;
      }
    }
  }

  update_screen();
}

int main( int argc, char* args[] )
{
    init();

    bool running = true;
    double prevtime = time_since_start();
    bool unlockFish[] = {true, false, false, false, false, false, false};
    int x[] = {48,117,186,247,320,393,466};
    while (running) {
        double now = time_since_start();
        double deltatime = now - prevtime;
        prevtime = now;

        handle_input();

        if (quit_pressed()) {
            running = false;
        } else {
          // Tangkap event mouse click
          switch (get_mouse_clicks()){
              case SDL_BUTTON_LEFT:
              break;
          }
        }

        // // Proses masukan yang bersifat "tombol"
        // for (auto key : get_tapped_keys()) {
        //     switch (key) {
        //     // r untuk reset
        //     case SDLK_r:
        //         cy = SCREEN_HEIGHT / 2;
        //         cx = SCREEN_WIDTH / 2;
        //         break;
        //     // x untuk keluar
        //     case SDLK_x:
        //         running = false;
        //         break;
        //     }
        // }
        updateAll(now, deltatime, unlockFish, x);
    }

    close();

    return 0;
}
