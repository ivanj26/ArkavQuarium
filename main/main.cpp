#include "oop.hpp"
#include <math.h>
#include "../src/LinkedList/LinkedList.cpp"
#include "../src/LinkedList/Node.cpp"
#include "../src/Player.cpp"
#include <string.h>

using namespace std;

const double speed = 50; // pixels per second

void updateAll(double now, int deltatime){
  clear_screen();
  /* Aquarium */
  draw_image(DIR_ICONS + "aquarium2.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  /* Setting menu bar*/
  draw_image(DIR_ICONS + "menubar.gif" , SCREEN_WIDTH / 2, 75 / 2);

  /* Print money*/
  Player::printMoney();
  update_screen();
}

int main( int argc, char* args[] )
{
    init();

    bool running = true;
    double prevtime = time_since_start();

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
        updateAll(now, deltatime);
    }

    close();

    return 0;
}
