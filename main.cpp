#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
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
    LinkedList<string> l;
    l.insert(1,"vnioenbvoetn");
    l.insert(1,"vnvberetbettebetrenbvoetn");
    l.insert(1,"vnioerstntnsrnoetn");
    l.insert(1,"vnawegrgrehbtsrhetn");
    l.insert(1,"vniotrhsrjstrjntn");
    l.displayAll();
    return 0;
}
