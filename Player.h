#ifndef PLAYER_H_
#define PLAYER_H_
#include "List.h"
#include "Card.h"
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

void Player::draw(Card add)
{
    on_hand->insert(1,add);
}

void Player::display_all()
{
    for(int i=1;i<=card_count;i++)
    {
        Card temp=on_hand->getEntry(i);
        string type=temp.get_type();
        if(type=="normal")
        {

        }
        else if(type=="forbidden")
        {

        }
        else if(type=="turnarund")
        {

        }
        else if(type=="add")
        {

        }
        else if(type=="selectcolor")
        {

        }
        else if(type=="almighty")
        {

        }
    }
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
}

#endif
