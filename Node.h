#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node//Node
{
private:
    T item;
    Node<T> *next;
public:
    Node();
    Node(const T&);
    Node(const T&,Node<T>*);
    void setItem(const T&);
    void setNext(Node<T>*);
    T getItem()const;
    Node<T> *getNext()const;
};

template <typename T>
Node<T>::Node():next(nullptr){}
template <typename T>
Node<T>::Node(const T &n):item(n),next(nullptr){}
template <typename T>
Node<T>::Node(const T &n,Node<T> *next):item(n),next(next){}
template <typename T>
void Node<T>::setItem(const T &it)
{
    this->item=it;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next=next;
}

template <typename T>
T Node<T>::getItem()const
{
    return item;
}

template <typename T>
Node<T>* Node<T>::getNext()const
{
    return next;
}

#endif
