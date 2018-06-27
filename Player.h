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
    LinkedList<Card> on_hand;
    int card_count;
public:
    Player(string name);
    void draw_card();
    void display_all();
    bool use_card(int pos);
    bool win();
};

#endif
