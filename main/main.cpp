#include "oop.hpp"
#include <math.h>
#include "../include/LinkedList/LinkedList.hpp"
#include "../include/LinkedList/Node.hpp"
#include "../include/Global.hpp"
#include "../src/Player.cpp"
#include <string.h>
#include <dirent.h>
#include <iostream>
using namespace std;

const double speed = 50; // pixels per second


string guppy_normal_gifs[30];
string piranha_normal_gifs[10];
void updateAll(double now, int deltatime, bool (&unlockFish)[7], int (&x) [7], int &j){
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
          draw_image(guppy_normal_gifs[j], x[i] , 25);
          draw_text("$" + to_string(PRC_GUPPY), 12, x[i] - 15, 45, 80, 255, 25);
          break;
        case 1:
          draw_image(DIR_ICONS + "food.png", x[i], 25);
          draw_text("$" + to_string(PRC_FOOD), 12, x[i] - 12, 45, 80, 255, 25);
          break;
        case 2:
          break;
        case 3:
          draw_image(piranha_normal_gifs[j], x[i], 25);
          draw_text("$" + to_string(PRC_PIRANHA), 12, x[i] - 17, 45, 80, 255, 35);
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          switch (Player::getEggLevel()) {
            case 0:
              draw_image(DIR_ICONS + "egg_1.png", x[i], 25);
              draw_text("$" + to_string(PRC_EGG_1), 12, x[i] - 17,45, 80, 255 ,35);
            break;
            case 1:
              draw_image(DIR_ICONS + "egg_2.png", x[i], 25);
              draw_text("$" + to_string(PRC_EGG_2), 12, x[i] - 17,45, 80, 255 ,35);
            break;
            default:
              draw_image(DIR_ICONS + "egg_3.png", x[i], 25);
              draw_text("$" + to_string(PRC_EGG_3), 12, x[i] - 17,45, 80, 255 ,35);
          }
          break;
      }
      if (j < 9)
        j++;
      else
        j = 0;
    }
  }

  update_screen();
}

int main( int argc, char* args[] )
{
    init();

    bool running = true;
    double prevtime = time_since_start();
    bool unlockFish[] = {true, true, false, false, false, false, true};
    int x[] = {48,117,186,247,320,393,466};

    //Catet nama file guppy gif & piranha gif
    string DIR_GUPPY_NORMAL = DIR_ICONS + "Animal/GuppyNormal/";
    string DIR_GUPPY_HUNGRY = DIR_ICONS + "Animal/GuppyHungry/";
    string DIR_PIRANHA_NORMAL = DIR_ICONS + "Animal/PiranhaNormal/";
    string DIR_PIRANHA_HUNGRY = DIR_ICONS + "Animal/PiranhaHungry/";

    DIR *dir = opendir(DIR_GUPPY_NORMAL.c_str());
  	dirent *pdir;
    char gif[] = "gif";
    char *contains = NULL;
  	while(pdir=readdir(dir))
  	{
      contains = strstr (pdir->d_name, gif);
      if (contains){
        int idx = int(pdir->d_name[10]) - 48;
        if (int(pdir->d_name[5]) == 49){
      		guppy_normal_gifs[idx] = DIR_GUPPY_NORMAL + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 50){
          guppy_normal_gifs[idx + 10] = DIR_GUPPY_NORMAL + pdir->d_name;
        } else {
          guppy_normal_gifs[idx + 20] = DIR_GUPPY_NORMAL + pdir->d_name;
        }
      }
  	}

    dir = opendir(DIR_PIRANHA_NORMAL.c_str());
    contains = NULL;
  	while(pdir=readdir(dir))
  	{
      contains = strstr (pdir->d_name, gif);
      if (contains){
        int idx = int(pdir->d_name[11]) - 48;
    		piranha_normal_gifs[idx] = DIR_PIRANHA_NORMAL + pdir->d_name;
      }
  	}

    int i = 0;
  	closedir(dir);

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
                int x_mouse = get_mouse_x();
                int y_mouse = get_mouse_y();

                if ((x_mouse <= x[0]+20 && x_mouse >= x[0]-20) && (y_mouse <= 45 && y_mouse >= 5)){
                  //Bila ingin membeli guppy
                  cout << "Buy guppy!" << endl;
                } else if ((x_mouse <= x[1]+20 && x_mouse >= x[1]-20) && (y_mouse <= 45 && y_mouse >= 5)) {
                  //Bila ingin membeli food
                  cout << "Buy food!" << endl;
                } else if ((x_mouse <= x[3]+20 && x_mouse >= x[3]-20) && (y_mouse <= 45 && y_mouse >= 5) && unlockFish[3]){
                  //Bila ingin membeli piranha
                  cout << "Buy piranha!" << endl;
                } else if ((x_mouse <= x[6]+20 && x_mouse >= x[6]-20) && (y_mouse <= 45 && y_mouse >= 5) && unlockFish[6]){
                  //Bila ingin membeli telur
                  cout << "Buy egg!" << endl;
                }
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
        SDL_Delay(20);
        updateAll(now, deltatime, unlockFish, x, i);
    }

    close();

    return 0;
}
