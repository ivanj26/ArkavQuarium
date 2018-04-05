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
        Node(const Node<T>&); //MARK (perubahan param Node jadi Node<T>)
        Node<T>& operator=(const Node<T>&); //MARK (perubahan param, dari Node jadi Node<T>)

        /*Get & Set prev next*/
        Node<T>* getNext();
        Node<T>* getPrev();
        void setNext(Node<T>*);
        void setPrev(Node<T>*);

        /*MARK (Penambahan method)*/
        /*Get & Set value*/
        T getValue();
        void setValue(T);
};

#endif
