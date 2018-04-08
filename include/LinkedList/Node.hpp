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

template <class T>
Node<T>::Node(){
  next = NULL;
  prev = NULL;
}

template <class T>
Node<T>::~Node(){
  if (prev != NULL && next != NULL){
    prev->setNext(next);
    next->setPrev(prev);
  } else if (prev != NULL && next == NULL){
    prev->setNext(NULL);
  } else if (prev == NULL && next != NULL){
    next->setPrev(NULL);
  }
}

template <class T>
Node<T>::Node(const Node& node){
  next = node->next;
  prev = node->prev;
  value = node->value;
}

template <class T>
Node<T>& Node<T>::operator=(const Node<T>& otherNode){
  Node<T>* node = new Node<T>;
  node->next = otherNode->next;
  node->prev = otherNode->prev;
  node->value = otherNode->value;
  return node;
}

/*Get & Set prev next*/
template <class T>
Node<T>* Node<T>::getNext(){
  return next;
}

template <class T>
Node<T>* Node<T>::getPrev(){
  return prev;
}

template <class T>
void Node<T>::setNext(Node<T>* next){
  this->next = next;
}

template <class T>
void Node<T>::setPrev(Node<T>* prev){
  this->prev = prev;
}

/*Get & Set value*/
template <class T>
T Node<T>::getValue(){
  return value;
}

template <class T>
void Node<T>::setValue(T value){
  this->value =  value;
}

#endif
