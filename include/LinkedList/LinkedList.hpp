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
        int getCurrentSize()const; //MARK (ada kesalahan parameternya, seharusnya tidak ada parameter)

        //MARK (ada penambahan mendapatkan Head)
        Node<T>* getHead();

        int find(T);
        void add(T);
        void remove(T);
        T getIndex(int);
};

#endif
