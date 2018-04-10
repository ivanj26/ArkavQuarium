#include "oop.hpp"
#include <math.h>
#include "../include/Aquarium.hpp"
#include "../include/Player.hpp"
#include <string.h>
#include <dirent.h>
#include <iostream>
using namespace std;

string foods_move_gifs[10];
string snail_move_gifs[10];
string guppy_gifs[120];
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
          draw_image(guppy_gifs[j], x[i] , 25);
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
  for (int i = 0; i < aquarium.getFishes().getCurrentSize(); i++){
    if (aquarium.getFishes().getHead()->getValue()->getID() == 0){
      Guppy *guppy = dynamic_cast<Guppy*> (aquarium.getFishes().getIndex(i));
      if (guppy->getHungerTime() <= 0){
        guppy->setIsFull(false);
      }
      guppy->printFish(guppy_gifs);
      if (aquarium.getFoods().getCurrentSize() == 0 || guppy->getIsFull()){
        if (guppy->getTimeDirection() <= 0){
          guppy->setTimeDirection(-1);
        } else {
          guppy->setTimeDirection(guppy->getTimeDirection() - 500);
        }
        guppy->setHungerTime(guppy->getHungerTime() - 100);
        guppy->Move(generateRandom(0,360), deltatime);
      } else if (aquarium.getFoods().getCurrentSize() > 0 && !guppy->getIsFull()){
        guppy->findNearestFoodOrFish(aquarium.getFoods(), deltatime);
      }
      guppy = nullptr;
      delete guppy;
    } else {
      Piranha *piranha = dynamic_cast<Piranha*> (aquarium.getFishes().getIndex(i));
      piranha->printFish(piranha_normal_gifs);

      if (aquarium.getFoods().getCurrentSize() == 0 || piranha->getIsFull()){
        piranha->Move(generateRandom(0,360), deltatime);
      } else if (aquarium.getFoods().getCurrentSize() > 0 && !piranha->getIsFull()){
        piranha->findNearestFoodOrFish(aquarium.getFishes(), deltatime);
      }

      piranha = nullptr;
      delete piranha;
    }
  }

  /*Move foods*/
  for (int i = 0; i < aquarium.getFoods().getCurrentSize(); i++){
    if (aquarium.getFoods().getIndex(i)->getIsReachBottom()){
      aquarium.getFoods().remove(i);
    } else {
      aquarium.getFoods().getIndex(i)->printFood(foods_move_gifs);
      aquarium.getFoods().getIndex(i)->Move(deltatime);
    }
  }

  /*Move coins*/
  // for (int i = 0; i < aquarium.getCoins().getCurrentSize(); i++){
  //   aquarium.getCoins().getIndex(i)->printCoin(coins_move_gifs);
  //   aquarium.getCoins().getIndex(i)->Move(deltatime);
  // }

  /*Move Snail*/
  aquarium.getSnail().printSnail(snail_move_gifs);
  if (aquarium.getCoins().getCurrentSize() == 0){
    if (aquarium.getSnail().getTimeDirection() <= 0){
      aquarium.getSnail().setTimeDirection(-1);
    } else {
      aquarium.getSnail().setTimeDirection(aquarium.getSnail().getTimeDirection() - 70);
    }
    aquarium.getSnail().Move(double(round(generateRandom(0,180))), deltatime);
  } else {
    aquarium.getSnail().findNearestCoin(aquarium.getCoins(), deltatime);
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
    string DIR_guppy = DIR_ICONS + "Animal/GuppyNormal/";
    string DIR_SNAIL_MOVE = DIR_ICONS + "Animal/SnailMove/";
    string DIR_FOODS = DIR_ICONS + "Animal/Foods/";
    string DIR_PIRANHA_NORMAL = DIR_ICONS + "Animal/PiranhaNormal/";
    string DIR_PIRANHA_HUNGRY = DIR_ICONS + "Animal/PiranhaHungry/";

    DIR *dir = opendir(DIR_guppy.c_str());
  	dirent *pdir;
    char gif[] = "gif";
    char *contains = NULL;
  	while(pdir=readdir(dir))
  	{
      contains = strstr (pdir->d_name, gif);
      if (contains){
        int idx = int(pdir->d_name[10]) - 48;
        if (int(pdir->d_name[5]) == 49 && int(pdir->d_name[8]) == 105){
      		guppy_gifs[idx] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 50 && int(pdir->d_name[8]) == 105){
          guppy_gifs[idx + 10] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 51 && int(pdir->d_name[8]) == 105) {
          guppy_gifs[idx + 20] = DIR_guppy + pdir->d_name;
        } else  if (int(pdir->d_name[5]) == 49 && int(pdir->d_name[8]) == 97){
          guppy_gifs[idx + 30] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 50 && int(pdir->d_name[8]) == 97){
          guppy_gifs[idx + 40] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 51 && int(pdir->d_name[8]) == 97){
          guppy_gifs[idx + 50] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 49 && int(pdir->d_name[8]) == 98){
          guppy_gifs[idx + 60] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 50 && int(pdir->d_name[8]) == 98){
          guppy_gifs[idx + 70] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 51 && int(pdir->d_name[8]) == 98){
          guppy_gifs[idx + 80] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 49 && int(pdir->d_name[8]) == 99){
          guppy_gifs[idx + 90] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 50 && int(pdir->d_name[8]) == 99){
          guppy_gifs[idx + 100] = DIR_guppy + pdir->d_name;
        } else if (int(pdir->d_name[5]) == 51 && int(pdir->d_name[8]) == 99){
          guppy_gifs[idx + 110] = DIR_guppy + pdir->d_name;
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
                } else if ((x_mouse <= SCREEN_WIDTH-40 && x_mouse >= 40) && (y_mouse <= SCREEN_HEIGHT-40 && y_mouse >= 115)) {
                  if (Player::getMoney() >= PRC_FOOD){
                      Player::setMoney(Player::getMoney() - PRC_FOOD);
                      Food *f = new Food();
                      f->setX(x_mouse);
                      f->setY(y_mouse);
                      aquarium.getFoods().add(f);
                      f = nullptr;
                      delete f;
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
        SDL_Delay(120);
        updateAll(now, deltatime, unlockFish, x, i, aquarium);
    }
    close();

    return 0;
}
