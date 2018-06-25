#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;

int main()
{
    LinkedQueue<string> q;
    q.enqueue("vnioernbv");
    q.enqueue("vnioeervervreverrnbv");
    q.enqueue("vnioerervvrvv");
    while(!q.isEmpty())
    {
        cout<<q.peekFront()<<endl;
        q.dequeue();
    }
    LinkedStack<string> s;
    s.push("vnioernbv");
    s.push("vnioeervervreverrnbv");
    s.push("vnioerervvrvv");
    while(!s.isEmpty())
    {
        cout<<s.peek()<<endl;
        s.pop();
    }
    return 0;
}
