#ifndef NODE_HPP
#define NODE_HPP

template <class T>
class Node{
    private:
        T value;
        Node<T>* next;
        Node<T>* prev;
    public:
        Node();
        ~Node();
        Node(const Node&);
        Node<T>& operator=(const Node&);

        /*Get & Set prev next*/
        Node<T>* getNext();
        Node<T>* getPrev();
        void setNext(Node<T>*);
        void setPrev(Node<T>*);
};

#endif