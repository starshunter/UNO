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
    NormalCard(int,string);
    int get_number();
    string get_color();
};

NormalCard::NormalCard(int number,string color)
{
    this->type="normal";
    this->number=number;
    this->color=color;
}

class ForbiddenCard:public Card
{
private:
    string type;
    string color;
public:
    ForbiddenCard(string);
    string get_color();
};

ForbiddenCard::ForbiddenCard(string color)
{
    this->type="forbidden";
    this->color=color;
}

class TurnaroundCard:public Card
{
private:
    string type;
    string color;
public:
    TurnaroundCard(string);
    string get_color();
};

TurnaroundCard::TurnaroundCard(string color)
{
    this->type="turnaround";
    this->color=color;
}

class AddCard:public Card
{
private:
    string type;
    string color;
    int add_card_num;
public:
    AddCard(int,string);
    string get_color();
    int get_add_card_num();
};

AddCard::AddCard(int add_card_num,string color)
{
    this->type="add";
    this->color=color;
    this->add_card_num=add_card_num;
}

class SelectColorCard:public Card
{
private:
    string type;
public:
    SelectColorCard();
};

SelectColorCard::SelectColorCard()
{
    this->type="selectcolor";
}

class AlmightyCard:public Card
{
private:
    string type;
public:
    AlmightyCard();
};

AlmightyCard::AlmightyCard()
{
    this->type="almighty";
}

#endif
