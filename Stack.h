#ifndef STACK_H_
#define STACK_H_
#include "Node.h"
template <typename T>
class StackInterace
{
public:
    virtual bool isEmpty()const=0;
    virtual bool push(const T &newEntry)=0;
    virtual bool pop()=0;
    virtual T peek()const=0;
};
template <typename T>
class LinkedStack:public StackInterace<T>
{
private:
    Node<T> *topPtr;
public:
    LinkedStack();
    LinkedStack(const LinkedStack<T> &aStack);
    bool isEmpty()const;
    bool push(const T &newItem);
    bool pop();
    ~LinkedStack();
    T peek()const;
};
template <typename T>
LinkedStack<T>::LinkedStack():topPtr(nullptr){}

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> &aStack)
{
    Node<T> *origChainPtr=aStack.topPtr;

    if(origChainPtr==nullptr)
        this->topPtr=nullptr;

    else
    {
        topPtr=new Node<T>();
        topPtr->setItem(origChainPtr->getItem());
        Node<T> *newChainPtr=topPtr;
        origChainPtr=origChainPtr->getNext();

        while(origChainPtr!=nullptr)
        {
            T nextItem=origChainPtr->getItem();
            Node<T> *newNodePtr=new Node<T>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr=newChainPtr->getNext();
            origChainPtr=origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template <typename T>
bool LinkedStack<T>::isEmpty()const
{
    if(topPtr==nullptr)
        return true;
    return false;
}

template <typename T>
bool LinkedStack<T>::push(const T &newItem)
{
    Node<T> *newNodePtr=new Node<T>(newItem,topPtr);
    topPtr=newNodePtr;
    newNodePtr=nullptr;
    return true;
}

template <typename T>
bool LinkedStack<T>::pop()
{
    if(!isEmpty())
    {
        Node<T> *nodeToDeletePtr=topPtr;
        topPtr=topPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr=nullptr;
        return true;
    }
    return false;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while(!isEmpty())
        pop();
}

template <typename T>
T LinkedStack<T>::peek()const
{
    assert(!isEmpty());
    return topPtr->getItem();
}
#endif
