#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>
using namespace std;

class Card
{
private:
    string type;
    string color;
    int number;
public:
    Card();
    Card(string,string,int);
    string get_type();
    string get_color();
    int get_number();
    void print();
};
Card::Card()
{
    type="";
    color="";
    number=0;
}

Card::Card(string type,string color,int number)
{
    this->type=type;
    this->color=color;
    this->number=number;
}
string Card::get_type()
{
    return type;
}
string Card::get_color()
{
    return color;
}
int Card::get_number()
{
    return number;
}
void Card::print()
{

}
#endif
