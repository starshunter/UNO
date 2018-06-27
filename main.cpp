#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "Player.h"
#include "Card.h"
using namespace std;

int main()
{
    LinkedQueue<string> q;
    q.enqueue("123");
    q.enqueue("1234");
    q.enqueue("12345");
    while(!q.isEmpty())
    {
        cout<<q.peekFront()<<endl;
        q.dequeue();
    }
    LinkedStack<string> s;
    s.push("123");
    s.push("1234");
    s.push("12345");
    while(!s.isEmpty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
    LinkedList<string> l;
    l.insert(1,"1");
    l.insert(1,"12");
    l.insert(1,"123");
    l.insert(1,"1234");
    l.insert(1,"12345");
    l.displayAll();
    return 0;
}
