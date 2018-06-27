#ifndef QUEUE_H_
#define QUEUE_H_
#include "Node.h"

template <typename T>
class QueueInterface//QueueInterface
{
public:
    virtual bool isEmpty()const=0;
    virtual bool enqueue(const T &newEntry)=0;
    virtual bool dequeue()=0;
    virtual T peekFront()const=0;
};
template <typename T>
class LinkedQueue:public QueueInterface<T>//LinkedQueue
{
private:
    Node<T> *frontPtr;
    Node<T> *backPtr;
    int size;
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue &aQueue);
    ~LinkedQueue();
    bool isEmpty()const;//chech if empty
    bool enqueue(const T &newEntry);//put item into queue
    bool dequeue();//pop out an item
    T peekFront()const;//see the item in the front
    int get_size()const;//get the size of queue
};

template <typename T>
LinkedQueue<T>::LinkedQueue():frontPtr(nullptr),backPtr(nullptr),size(0){}
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue &aQueue)
{
    Node<T> *origChainPtr=aQueue.frontPtr;
    if(origChainPtr==nullptr)
    {
        frontPtr=nullptr;
        backPtr=nullptr;
    }
    else
    {
        frontPtr=new Node<T>();
        frontPtr->setItem(origChainPtr->getItem());
        origChainPtr=origChainPtr->getNext();
        Node<T> *newChainPtr=frontPtr;
        while(origChainPtr!=nullptr)
        {
            T nextItem=origChainPtr->getgetItem();
            Node<T> *newNodePtr=new Node<T>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr=newChainPtr->getNext();
            origChainPtr=origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
        backPtr=newChainPtr;
    }
    this->size=aQueue.size;
}
template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    while(!isEmpty())
    {
        dequeue();
    }
    size=0;
    assert((backPtr==nullptr)&&(frontPtr==nullptr));
}
template <typename T>
bool LinkedQueue<T>::isEmpty()const
{
    return backPtr==nullptr;
}
template <typename T>
bool LinkedQueue<T>::enqueue(const T &newEntry)
{
    Node<T> *newNodePtr=new Node<T>(newEntry);
    if(isEmpty())
        frontPtr=newNodePtr;
    else
        backPtr->setNext(newNodePtr);
    backPtr=newNodePtr;
    size++;
    return true;
}
template <typename T>
bool LinkedQueue<T>::dequeue()
{
    bool result=false;
    if(!isEmpty())
    {
        Node<T> *nodeToDeletePtr=frontPtr;
        if(frontPtr==backPtr)
        {
            frontPtr=nullptr;
            backPtr=nullptr;
        }
        else
            frontPtr=frontPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr=nullptr;
        result=true;
        size--;
    }
    return result;
}
template <typename T>
T LinkedQueue<T>::peekFront()const
{
    assert(!isEmpty());
    return frontPtr->getItem();
}
template <typename T>
int LinkedQueue<T>::get_size()const
{
    return size;
}

#endif
