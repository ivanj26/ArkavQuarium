#ifndef LL_HPP
#define LL_HPP

template <class T>
class LinkedList{
    private:
        int currentSize;
        bool isEmpty;
        T* Head;
        T* Tail;
    public:
        LinkedList();
        ~LinkedList();
        
        /*Get & Set IsEmpty*/
        bool getIsEmpty() const;
        void setIsEmpty(bool);

        /*Get & Set currenSize*/
        void setCurrentSize(int);
        int getCurrentSize(int)const;

        int find(T*);
        void add(T*);
        void remove(T*);
        T* getIndex(int);
};

#endif
