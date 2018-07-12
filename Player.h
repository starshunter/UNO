#ifndef PLAYER_H_
#define PLAYER_H_
#include "List.h"
#include "Card.h"
#include "ConsoleColor.h"
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    LinkedList<Card> *on_hand;
    int card_count;
public:
    Player(string name);
    string get_name();
    void draw(Card);
    void display_all();
    int get_card_count();
    Card use_card(int pos);
    void remove_card(int pos);
    bool win();
};

Player::Player(string name):name(name),card_count(0)
{
    on_hand=new LinkedList<Card>;
}

string Player::get_name()
{
    return name;
}

void Player::draw(Card add)
{
    on_hand->insert(1,add);
    card_count++;
}

void Player::display_all()
{
    int row=(card_count-1)/5+1;
    int **arr=new int*[17*row];
    for(int i=0;i<17*row;i++)
        arr[i]=new int[84];

    for(int i=0;i<17*row;i++)
        for(int j=0;j<84;j++)
            arr[i][j]=0;

    for(int i=1;i<=card_count;i++)
    {
        Card temp=on_hand->getEntry(i);
        cout<<temp.get_type()<<" "<<temp.get_color()<<" "<<temp.get_number()<<endl;
        int pos_i,pos_j;
        pos_i=((i-1)/7)*17;
        pos_j=((i-1)%7)*12;
        temp.print(arr,pos_i,pos_j);
    }
    /*for(int i=0;i<17*row;i++)
    {
		for(int j=0;j<60;j++)
    	{
    		cout << arr[i][j];
		}
		cout << endl;
	}*/
	
	cout<<white<<endl;
    for(int i=0;i<17*row;i++)
    {
        for(int j=0;j<84;j++)
        {
            if(arr[i][j]==0)
            {
                cout<<"  ";
            }
            else if(arr[i][j]==1)
            {
                cout<<white<<"■";
            }
            else if(arr[i][j]==2)
            {
                cout<<blue<<"■";
            }
            else if(arr[i][j]==3)
            {
                cout<<red<<"■";
            }
            else if(arr[i][j]==4)
            {
                cout<<yellow<<"■";
            }
            else if(arr[i][j]==5)
            {
                cout<<green<<"■";
            }
            else if(arr[i][j]==7)
            {
                cout<<"+4";
            }
            else if(arr[i][j]==8)
            {
                cout<<blue<<"▂";
            }
            else if(arr[i][j]==9)
            {
                cout<<red<<"▂";
            }
            else if(arr[i][j]==10)
            {
                cout<<yellow<<"▂";
            }
            else if(arr[i][j]==11)
            {
                cout<<green<<"▂";
            }
            else if(arr[i][j]==12)
            {
                cout<<"▋";
            }
            else if(arr[i][j]==13)
            {
                cout<<"▋";
            }
            else if(arr[i][j]==14)
            {
                cout<<"▋";
            }
            else if(arr[i][j]==15)
            {
                cout<<"▋";
            }
        }
        cout<<"\n";
    }
    cout<<white<<endl;
}

int Player::get_card_count()
{
    return card_count;
}

Card Player::use_card(int pos)
{
    Card temp=on_hand->getEntry(pos);
    return temp;
}

bool Player::win()
{
    return card_count==0;
}

void Player::remove_card(int pos)
{
    on_hand->remove(pos);
    card_count--;
}

#endif
