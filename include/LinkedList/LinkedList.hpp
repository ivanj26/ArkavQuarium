#include <iostream>
#include "Node.hpp"

using namespace std;
#ifndef LL_HPP
#define LL_HPP

template <class T>
class LinkedList{
    private:
        int currentSize;
        Node<T>* Head;
    public:
        LinkedList();
        ~LinkedList();

        bool isEmpty()const;

        /*Get & Set currenSize*/
        void setCurrentSize(int);
        int getCurrentSize()const; //MARK (ada kesalahan parameternya, seharusnya tidak ada parameter)

        //MARK (ada penambahan mendapatkan Head)
        Node<T>* getHead();

        int find(T);
        void add(T);
        void remove(T);
        void remove(int);
        T getIndex(int);
};

template <class T>
LinkedList<T>::LinkedList(){
  Head = NULL;
  currentSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
  for (int i = 0; i < currentSize; i++){
    Node<T> *temp = Head->getNext();
    delete Head;
    Head = temp;
  }
  delete Head;
}

template <class T>
bool LinkedList<T>::isEmpty()const{
  return currentSize == 0;
}

template <class T>
void LinkedList<T>::setCurrentSize(int currentSize){
  this->currentSize =  currentSize;
}

template <class T>
int LinkedList<T>::getCurrentSize() const{
  return currentSize;
}

template <class T>
Node<T>* LinkedList<T>::getHead(){
  return Head;
}


template <class T>
int LinkedList<T>::find(T value){
  if (currentSize >= 1){ //Kasus >=1 elmt
    int i = 0;
    bool isFound = false;
    Node<T> *temp = Head;
    while (temp != NULL && !isFound){
      if (temp->getValue() != value){
        temp = temp->getNext();
        i++;
      } else {
        isFound = true;
      }
    }

    if (!isFound){ //gak ketemu
      i = -1;
    }
    return i;
  } else { //Kasus kosong, kembalikan -1
    return -1;
  }
}

template <class T>
void LinkedList<T>::add(T value){
    if (currentSize > 1){ //Kasus >1 elmt
      for (int i = 0; i < currentSize-1; i++){
        Head = Head->getNext();
      }
      Node<T> *node = new Node<T>;
      node->setNext(NULL);
      node->setPrev(Head);
      node->setValue(value);
      Head->setNext(node);

      //Balik ke posisi head sebelumnya
      for (int i = 0; i < currentSize-1; i++){
        Head = Head->getPrev();
      }

  } else if (currentSize == 0) { //Kasus kosong
      Head = new Node<T>();
      Head->setValue(value);
      Head->setNext(NULL);
      Head->setPrev(NULL);
  } else { //Kasus 1 elmt
      Node<T>* node = new Node<T>();
      node->setValue(value);
      node->setPrev(Head);
      node->setNext(NULL);
      Head->setNext(node);
  }
  currentSize++;
}

template <class T>
void LinkedList<T>::remove(int idx){
  if (idx < currentSize){
    if (idx == 0 && currentSize == 1){
      delete Head;
    } else if (idx == 0 && currentSize > 1){
      Node<T>* next = Head->getNext();
      next->setPrev(NULL);
      delete Head;
      Head = next;
    } else {
      for (int i = 0; i < idx; i++){
        Head = Head->getNext();
      }

      Node<T> *prev = Head->getPrev();
      Node<T> *next = Head->getNext();

      if (next != NULL){
        next->setPrev(prev);
        prev->setNext(next);
      } else {
        prev->setNext(NULL);
      }

      Head = NULL;
      delete Head;
      Head = prev;

      for (int i = 0; i < idx-1; i++){
        Head = Head->getPrev();
      }
    }
    currentSize--;
  }
}

template <class T>
void LinkedList<T>::remove(T value){
  if (currentSize > 0){
    int idx = find(value);

    if (idx != -1){
      for (int i = 0; i < idx; i++){
        Head = Head->getNext();
      }

      Node<T> *prev = Head->getPrev();
      if (Head->getNext() != NULL){
        prev->setNext(Head->getNext());
        Head->getNext()->setPrev(prev);
      } else {
        prev->setNext(NULL);
      }

      delete Head;
      Head = prev;

      while (Head->getPrev() != NULL){
        Head = Head->getPrev();
      }

      currentSize--;
    }
  }
}

template <class T>
T LinkedList<T>::getIndex(int n){
  if (n >= currentSize){
    T *t = nullptr;
    return *t;
  } else {
    Node<T> *current = Head;
    int i = 0;
    while (i < n){
      current = current->getNext();
      i++;
    }
    return current->getValue();
  }
}

#endif
