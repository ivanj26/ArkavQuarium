#include "oop.hpp"
#include <math.h>
#include "../include/Aquarium.hpp"
#include "../include/Player.hpp"
#include <string.h>
#include <dirent.h>
#include <iostream>
using namespace std;

const double speed = 50; // pixels per second

string foods_move_gifs[10];
string snail_move_gifs[10];
string guppy_normal_gifs[30];
string piranha_normal_gifs[10];
void updateAll(double now, double deltatime, bool (&unlockFish)[7], int (&x) [7], int &j, Aquarium& aquarium){
  clear_screen();
  /* Draw aquarium & menu_bar to screen*/
  draw_image(DIR_ICONS + "aquarium2.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  draw_image(DIR_ICONS + "menubar.gif" , SCREEN_WIDTH / 2, 75 / 2);

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

  /* Print player's money,etc*/
  Player::printMoney();

  /* Update semua fish, food, dan coin*/
  aquarium.getSnail().printSnail(snail_move_gifs);
  aquarium.getSnail().Move(double(round(generateRandom(0,180))), deltatime);
  for (int i = 0; i < aquarium.getFishes().getCurrentSize(); i++){
    if (aquarium.getFishes().getHead()->getValue()->getID() == 0){
      Guppy *guppy = dynamic_cast<Guppy*> (aquarium.getFishes().getIndex(i));
      guppy->printFish(guppy_normal_gifs, guppy_normal_gifs);
      guppy = nullptr;
      delete guppy;
    } else {
      Piranha *piranha = dynamic_cast<Piranha*> (aquarium.getFishes().getIndex(i));
      piranha->printFish(piranha_normal_gifs, piranha_normal_gifs);
      piranha = nullptr;
      delete piranha;
    }
  }

  for (int i = 0; i < aquarium.getFoods().getCurrentSize(); i++){
      Food food = (aquarium.getFoods().getIndex(i));
      food.printFood(foods_move_gifs);
  }

  update_screen();
}

int main( int argc, char* args[] )
{
    init();

    bool running = true;
    double prevtime = time_since_start();
    bool unlockFish[] = {true, true, false, true, false, false, true};
    int x[] = {48,117,186,247,320,393,466};

    //Catet nama file guppy gif, piranha gif, dan gif lain
    string DIR_GUPPY_NORMAL = DIR_ICONS + "Animal/GuppyNormal/";
    string DIR_GUPPY_HUNGRY = DIR_ICONS + "Animal/GuppyHungry/";
    string DIR_SNAIL_MOVE = DIR_ICONS + "Animal/SnailMove/";
    string DIR_FOODS = DIR_ICONS + "Animal/Foods/";
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

    dir = opendir(DIR_SNAIL_MOVE.c_str());
    contains = NULL;
  	while(pdir=readdir(dir))
  	{
      contains = strstr (pdir->d_name, gif);
      if (contains){
        int idx = int(pdir->d_name[9]) - 48;
    	  snail_move_gifs[idx] = DIR_SNAIL_MOVE + pdir->d_name;
      }
  	}

    dir = opendir(DIR_FOODS.c_str());
    contains = NULL;
    while(pdir=readdir(dir))
    {
      contains = strstr (pdir->d_name, gif);
      if (contains){
        int idx = int(pdir->d_name[4]) - 48;
        foods_move_gifs[idx] = DIR_FOODS + pdir->d_name;
      }
    }

    int i = 0;
  	closedir(dir);


    //Instantiate aquarium
    Aquarium aquarium;
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
                  if (Player::getMoney() >= PRC_GUPPY){
                      Player::setMoney(Player::getMoney() - PRC_GUPPY);
                      Guppy* g = new Guppy();
                      g->setX(generateRandom(40, SCREEN_WIDTH-40));
                      g->setY(generateRandom(115, SCREEN_HEIGHT-40));
                      aquarium.getFishes().add(g);
                      g = nullptr;
                      delete g;
                  }
                } else if ((x_mouse <= x[1]+20 && x_mouse >= x[1]-20) && (y_mouse <= 45 && y_mouse >= 5)) {
                  if (Player::getMoney() >= PRC_FOOD){
                      Player::setMoney(Player::getMoney() - PRC_FOOD);
                      Food f;
                      f.setX(generateRandom(40, SCREEN_WIDTH-40));
                      f.setY(115);
                      aquarium.getFoods().add(f);
                  }
                } else if ((x_mouse <= x[3]+20 && x_mouse >= x[3]-20) && (y_mouse <= 45 && y_mouse >= 5) && unlockFish[3]){
                  if (Player::getMoney() >= PRC_PIRANHA){
                      Player::setMoney(Player::getMoney() - PRC_PIRANHA);
                      Piranha *p = new Piranha();
                      p->setX(generateRandom(40, SCREEN_WIDTH-40));
                      p->setY(generateRandom(115, SCREEN_HEIGHT-40));
                      aquarium.getFishes().add(p);
                      p = nullptr;
                      delete p;
                  }
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
        SDL_Delay(50);
        updateAll(now, deltatime, unlockFish, x, i, aquarium);
    }

    close();

    return 0;
}
