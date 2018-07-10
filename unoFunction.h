#ifndef UNOFUNCTION_H_
#define UNOFUNCTION_H_
#include "Stack.h"
#include "Player.h"
#include "Card.h"
#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

void initialCardStack(LinkedStack<Card>&);
void shuffle(LinkedStack<Card>&);
void draw_card(LinkedStack<Card>&,Player);
bool Nobody_win(LinkedQueue<Player>&,int);
void refill(LinkedStack<Card>&,LinkedStack<Card>&);
bool able_to_use(Card,string,int);

void initialCardStack(LinkedStack<Card> &cStack)
{
	Card rNcard("Normal","red",0);
	cStack.push(rNcard);
	Card gNcard("Normal","green",0);
	cStack.push(gNcard);
	Card bNcard("Normal","blue",0);
	cStack.push(bNcard);
	Card yNcard("Normal","yellow",0);
	cStack.push(yNcard);

	for(int i=0;i<9;i++)
	{
		Card rNcard("Normal","red",i);
		cStack.push(rNcard);
		Card gNcard("Normal","green",i);
		cStack.push(gNcard);
		Card bNcard("Normal","blue",i);
		cStack.push(bNcard);
		Card yNcard("Normal","yellow",i);
		cStack.push(yNcard);
	}

	Card rFcard("Forbidden","red",-1);
	cStack.push(rFcard);
	Card gFcard("Forbidden","green",-1);
	cStack.push(gFcard);
	Card bFcard("Forbidden","blue",-1);
	cStack.push(bFcard);
	Card yFcard("Forbidden","yellow",-1);
	cStack.push(yFcard);

	for(int i=0;i<2;i++)
	{
		Card rAcard("Add","red",-1);
		cStack.push(rAcard);
		Card gAcard("Add","green",-1);
		cStack.push(gAcard);
		Card bAcard("Add","blue",-1);
		cStack.push(bAcard);
		Card yAcard("Add","yellow",-1);
		cStack.push(yAcard);
	}

	Card rTcard("Turnaround","red",-1);
	cStack.push(rTcard);
	Card gTcard("Turnaround","green",-1);
	cStack.push(gTcard);
	Card bTcard("Turnaround","blue",-1);
	cStack.push(bTcard);
	Card yTcard("Turnaround","yellow",-1);
	cStack.push(yTcard);

	for(int i=0;i<4;i++)
	{
		Card SCcard("SelectColor","none",-1);
		cStack.push(SCcard);
		Card ALcard("Almighty","none",-1);
		cStack.push(ALcard);
	}
}
void shuffle(LinkedStack<Card> &cStack)
{
	LinkedStack<Card> temp;
	int count=0;
	while(!cStack.isEmpty())
	{
		temp.push(cStack.peek());
		cStack.pop();
		count++;
	}
	Card* array1=new Card[count];
	Card* array2=new Card[count];
	for(int i=0;i<count;i++)
	{
		Card card=temp.peek();
		array1[i]=card;
		temp.pop();
	}
	int index=count;
	bool* check = new bool[count];
	for(int i=0;i<count;i++)
		check[i]=false;
	for(int i=0;i<count;i++)
	{
		int insert=rand()%index;
		int pos=0;
		while(insert)
		{
			if(check[pos])
				pos++;
			else
			{
				pos++;
				insert--;
			}
		}
		array2[pos]=array1[i];
		index--;
	}
	for(int i=0;i<count;i++)
		cStack.push(array2[i]);
}
void draw_card(LinkedStack<Card> &cStack,Player p)
{
	Card temp=cStack.peek();
	cStack.pop();
	p.draw(temp);
}
bool Nobody_win(LinkedQueue<Player> &pQueue,int player_num)
{
	for(int i=0;i<player_num;i++)
	{
		if((pQueue.peekFront()).win())
			return false;
		else
		{
			Player temp=pQueue.peekFront();
			pQueue.dequeue();
			pQueue.enqueue(temp);
		}
	}
	return true;
}
void refill(LinkedStack<Card> &cStack,LinkedStack<Card> &uStack)
{
	while(!uStack.isEmpty())
	{
		cStack.push(uStack.peek());
		uStack.pop();
	}
}

bool able_to_use(Card c,string current_color,int current_number)
{
    if(!c.get_color().compare("none"))
        return true;
    if(!c.get_color().compare(current_color))
        return true;
    if(c.get_number()==current_number)
        return true;
    return false;
}

#endif
