#include "oop.hpp"
#include <math.h>
#include "../src/LinkedList/LinkedList.cpp"
#include "../src/LinkedList/Node.cpp"
#include <string.h>

using namespace std;

const double speed = 50; // pixels per second

void drawGuppy(int level){
  // switch (level) {
  //   case 1:
  //     draw_image(DIR_ICONS + "guppy_normal_1.png", generateRandom(40, SCREEN_WIDTH - 40), generateRandom(75 + 40, SCREEN_HEIGHT - 40));
  //   break;
  //   case 2:
  //     draw_image(DIR_ICONS + "guppy_normal_2.png", generateRandom(40, SCREEN_WIDTH - 40), generateRandom(75 + 40, SCREEN_HEIGHT - 40));
  //   break;
  //   case 3:
  //     draw_image(DIR_ICONS + "guppy_normal_3.png",generateRandom(40, SCREEN_WIDTH - 40), generateRandom(75 + 40, SCREEN_HEIGHT - 40));
  //   break;
  // }
}

void updateAll(double now, int deltatime){
  clear_screen();
  /* Aquarium */
  draw_image(DIR_ICONS + "aquarium2.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

  /* Setting menu bar*/
  draw_image(DIR_ICONS + "menubar.gif" , SCREEN_WIDTH / 2, 75 / 2);

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
