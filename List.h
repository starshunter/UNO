#ifndef LIST_H_
#define LIST_H_
#include "Node.h"
#include <iostream>
#include <assert.h>
#include <stdexcept>
#include <string>
using namespace std;
template <typename T>
class ListInterface
{
public:
    virtual bool isEmpty()const=0;
    virtual int getLength()const=0;
    virtual bool insert(int new_position,const T &newEntry)=0;
    virtual bool remove(int position)=0;
    virtual void clear()=0;
    virtual T getEntry(int position)const=0;
    virtual void setEntry(int position,const T &newEntry)=0;
};
template <typename T>
class LinkedList : public ListInterface<T>
{
private:
    Node<T>* headPtr;
    int itemCount;
    Node<T>* getNodeAt(int position) const ;
public:
    LinkedList();
    LinkedList(const LinkedList<T>& aList);
    virtual ~LinkedList();
    bool isEmpty()const ;
    int getLength()const ;
    bool insert(int newPosition,const T &newEntry);
    bool remove(int position);
    void clear();
    T getEntry(int position)const throw(runtime_error);
    void setEntry(int position,const T &newEntry)throw(runtime_error);
    void displayAll()const;
};
#endif

template <typename T>
Node<T>* LinkedList<T>::getNodeAt( int position) const
{
    assert ( (position >= 1) && (position <= itemCount) );
    Node<T>* curPtr = headPtr;
    for ( int skip = 1; skip < position; skip++)
    curPtr = curPtr->getNext();
    return curPtr ;
}

template <typename T>
LinkedList<T>::LinkedList() : headPtr( nullptr), itemCount(0)
{
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &aList):itemCount(aList.itemCount)
{
    Node<T> *origChainPtr=aList.headPtr;
    if(origChainPtr==nullptr)
    {
        headPtr=new Node<T>();
        headPtr->setItem(origChainPtr->getItem());
        Node<T> *newChainPtr=headPtr;
        origChainPtr=origChainPtr->getNext();
        while(origChainPtr!=nullptr)
        {
            Node<T>* newNodePtr = new Node<T>(origChainPtr->getItem());
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
bool LinkedList<T>::isEmpty()const
{
    return itemCount==0;
}

template <typename T>
int LinkedList<T>::getLength()const
{
    return itemCount;
}

template <typename T>
bool LinkedList<T>::insert(int newPosition,const T &newEntry)
{
    bool ableToInsert=(newPosition>=1)&&(newPosition<=itemCount+1);
    if(ableToInsert)
    {
        Node<T> *newNodePtr=new Node<T>(newEntry);
        if(newPosition==1)
        {
            newNodePtr->setNext(headPtr);
            headPtr=newNodePtr;
        }
        else
        {
            Node<T> *prevPtr=getNodeAt(newPosition-1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
    return ableToInsert;
}

template <typename T>
bool LinkedList<T>::remove(int position)
{
    bool ableToRemove=(position>=1)&&(position<=itemCount);
    if(ableToRemove)
    {
        Node<T> *curPtr=nullptr ;
        if(position==1)
        {
            curPtr=headPtr;
            headPtr=headPtr->getNext();
        }
        else
        {
            Node<T> *prevPtr=getNodeAt(position-1);
            curPtr=prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr=nullptr ;
        itemCount--;
    }
    return ableToRemove;
}

template <typename T>
void LinkedList<T>::clear()
{
    while(!isEmpty())
        remove(1);
}

template <typename T>
T LinkedList<T>::getEntry(int position)const throw(runtime_error)
{
    bool ableToGet=(position>=1)&&(position<=itemCount);
    if (ableToGet)
    {
       Node<T> *nodePtr=getNodeAt(position);
       return nodePtr->getItem();
    }
    else
    {
       string message="getEntry() called with an empty list or ";
       message=message+"invalid position.";
       throw(runtime_error(message));
    }
 }

template <typename T>
void LinkedList<T>::setEntry(int pos,const T &newEntry)throw(runtime_error)
{
    bool ableToSet=(pos>=1)&&(pos<=itemCount);
    if(ableToSet)
    {
        Node<T> *nodePtr=getNodeAt(pos);
        nodePtr->setItem(newEntry);
    }
    else
    {
        string message="setEntry() called with an invalid pos.";
        throw(runtime_error(message));
    }
}

template <typename T>
void LinkedList<T>::displayAll()const
{
    for(int i=0;i<itemCount;i++)
        cout<<getEntry(i+1)<<endl;
}
