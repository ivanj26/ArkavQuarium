#include "../../include/Animal/Snail.hpp"

Snail::Snail(){
  location.x = generateRandom(40, SCREEN_WIDTH-40);
  location.y = SCREEN_HEIGHT - 40;
  amountCoin = 0;
}

Snail& Snail::operator=(const Snail& s){//4 sekawan, untuk operator assignment
  this->amountCoin = s.amountCoin;
  this->location.x = s.location.x;
  this->location.y = s.location.y;
  return *this;
}


/* KASUS I  = Kalau ada koin dia didekatnya, dia gerak ke lokasi koin
 * KASUS II = Kalau ga ada koin, dia diem
*/
void Snail::insertCoin(Coin c){
  amountCoin += c.getValue();
}

/*degree selalu 180 atau 0*/
void Snail::Move(double degree, double deltatime){
  bool isInsideX = ((location.x + int(SPEED_SNAIL * deltatime * cos(degree * (M_PI / 180)))) <= SCREEN_WIDTH - 40);

  while (!(isInsideX)){
    /*Cari arah baru, karena mau lewatin aquarium*/
    degree = generateRandom(0,180);
    degree = double(round(degree)) * 180;
    isInsideX = ((location.x + int(SPEED_SNAIL * deltatime * cos(degree * (M_PI / 180)))) <= SCREEN_WIDTH - 40);
  }

  location.x += int(SPEED_SNAIL * deltatime * cos(degree * (M_PI / 180)));
}

/*Get & Set*/
void Snail::setX(int x){location.x = x;}
int Snail::getX()const{return location.x;}
void Snail::setY(int y){location.y = y;}
int Snail::getY()const{return location.y;}

/*Get & Set amountCoin*/
void Snail::setAmountCoin(int amountCoin){
  this->amountCoin = amountCoin;
}

int Snail::getAmountCoin()const{
  return amountCoin;
}

void Snail::findNearestCoin(LinkedList<Coin> Coins, double deltatime){
  Node<Coin> *node = Coins.getHead();
  double tempMin = sqrt(pow(getX() - node->getValue().getX(),2) + pow(getY() - node->getValue().getY(),2));

  if (tempMin == 0){ //Coin tepat di posisi snail
    insertCoin(node->getValue());
    Coins.remove(node->getValue());
  } else {
      int i = 1;
      Node<Coin> *minNode = Coins.getHead();

      while (tempMin != 0 && i < Coins.getCurrentSize()){
        node = node->getNext();
        double temp = sqrt(pow(getX() - node->getValue().getX(),2) + pow(getY() - node->getValue().getY(),2));
        if (tempMin >  temp){
          tempMin = temp;
          minNode = node;
        }
        i++;
      }

      //Bergerak ke arah coin terdekat
      int deltaY = getY() - minNode->getValue().getY();
      int deltaX = getX() - minNode->getValue().getX();

      double degree = atan(deltaY / deltaX) * (180 / M_PI);
      Move(double(round(degree)) * 180, deltatime);
    }
}

int Snail::getStateGambar(){return stateGambar;}

void Snail::setStateGambar(int i){
  stateGambar = i;
}

void Snail::printSnail(string snail_move[]){
  draw_image(snail_move[getStateGambar()], getX(), getY());
  if (getStateGambar() != 9)
    setStateGambar(getStateGambar() + 1);
  else
    setStateGambar(0);
}
