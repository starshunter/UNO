#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>
using namespace std;

class Card
{
private:
    string type;
public:
    string get_type();
};

string Card::get_type()
{
    return type;
}

class NormalCard:public Card
{
private:
    string type;
    int number;
    string color;
public:
    int get_number();
    string get_color();
};

class ForbiddenCard:public Card
{
private:
    string type;
    string color;
public:
    string get_color();
};

class TurnaroundCard:public Card
{
private:
    string type;
    string color;
public:
    string get_color();
};

class AddCard:public Card
{
private:
    string type;
    string color;
    int add_card_num;
public:
    string get_color();
    int get_add_card_num();
};

class SelectColorCard:public Card
{
private:
    string type;
};

class AlmightyCard:public Card
{
private:
    string type;
};

#endif
