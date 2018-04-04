#include "Node.hpp"

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
        int getCurrentSize(int)const;

        int find(T);
        void add(T);
        void remove(T);
        T getIndex(int);
};

#endif
