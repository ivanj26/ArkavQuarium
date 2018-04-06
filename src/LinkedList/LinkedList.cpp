#include "../../include/LinkedList/LinkedList.hpp"
#include <iostream>

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
    return NULL;
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
