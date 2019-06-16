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
    void print(int**,int,int);
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
void Card::print(int **arr,int pos_i,int pos_j)
{
    if(type=="Normal")
    {
        if(number==0)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==1)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,0,0,1,1,1,1,
						   1,1,1,0,1,0,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==2)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,0,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,0,1,1,1,1,1,1,
						   1,1,0,0,0,0,0,0,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==3)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,0,0,1,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==4)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,0,1,1,1,
						   1,1,1,1,1,0,0,1,1,1,
						   1,1,1,1,0,1,0,1,1,1,
						   1,1,1,0,1,1,0,1,1,1,
						   1,1,0,1,1,1,0,1,1,1,
						   1,0,1,1,1,1,0,1,1,1,
						   1,0,0,0,0,0,0,0,1,1,
						   1,1,1,1,1,1,0,1,1,1,
						   1,1,1,1,1,1,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==5)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,0,0,0,0,0,0,1,1,
						   1,1,0,1,1,1,1,1,1,1,
						   1,1,0,1,1,1,1,1,1,1,
						   1,1,0,1,1,1,1,1,1,1,
						   1,1,0,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==6)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,1,1,1,
						   1,1,0,1,1,1,1,1,1,1,
						   1,1,0,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==7)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,0,0,0,0,0,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,0,1,1,1,
						   1,1,1,1,1,0,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==8)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
        if(number==9)
        {
            int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,1,1,1,1,1,0,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(display[i][j])
                    {
                        if(color=="blue")
                            arr[pos_i+i][pos_j+j]=2;
                        else if(color=="red")
                            arr[pos_i+i][pos_j+j]=3;
                        else if(color=="yellow")
                            arr[pos_i+i][pos_j+j]=4;
                        else if(color=="green")
                            arr[pos_i+i][pos_j+j]=5;
                    }
                    else
                        arr[pos_i+i][pos_j+j]=0;
                }
            }
        }
    }
    else if(type=="Forbidden")
    {
        int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,0,1,1,1,1,0,1,1,
						   1,0,1,0,1,1,1,1,0,1,
						   1,0,1,1,0,1,1,1,0,1,
						   1,0,1,1,1,0,1,1,0,1,
						   1,1,0,1,1,1,0,0,1,1,
						   1,1,1,0,0,0,0,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(display[i][j])
                {
                    if(color=="blue")
                        arr[pos_i+i][pos_j+j]=2;
                    else if(color=="red")
                        arr[pos_i+i][pos_j+j]=3;
                    else if(color=="yellow")
                        arr[pos_i+i][pos_j+j]=4;
                    else if(color=="green")
                        arr[pos_i+i][pos_j+j]=5;
                }
                else
                    arr[pos_i+i][pos_j+j]=0;
            }
        }
    }
    else if(type=="Add")
    {
        int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,0,0,0,0,1,1,
						   1,1,1,1,0,0,0,0,1,1,
						   1,1,1,1,0,0,0,0,1,1,
						   1,1,1,1,2,2,0,0,1,1,
						   1,1,0,0,0,0,3,0,1,1,
						   1,1,0,0,0,0,3,0,1,1,
						   1,1,0,0,0,0,1,1,1,1,
						   1,1,0,0,0,0,1,1,1,1,
						   1,1,0,0,0,0,1,1,1,1,
						   1,1,0,0,0,0,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(display[i][j])
                {
                    if(color=="blue")
                    {
                        if(display[i][j]==1)
                            arr[pos_i+i][pos_j+j]=2;
                        else if(display[i][j]==2)
                            arr[pos_i+i][pos_j+j]=8;
                        else if(display[i][j]==3)
                            arr[pos_i+i][pos_j+j]=12;
                    }
                    else if(color=="red")
                    {
                        if(display[i][j]==1)
                            arr[pos_i+i][pos_j+j]=3;
                        else if(display[i][j]==2)
                            arr[pos_i+i][pos_j+j]=9;
                        else if(display[i][j]==3)
                            arr[pos_i+i][pos_j+j]=13;
                    }
                    else if(color=="yellow")
                    {
                        if(display[i][j]==1)
                            arr[pos_i+i][pos_j+j]=4;
                        else if(display[i][j]==2)
                            arr[pos_i+i][pos_j+j]=10;
                        else if(display[i][j]==3)
                            arr[pos_i+i][pos_j+j]=14;
                    }
                    else if(color=="green")
                    {
                        if(display[i][j]==1)
                            arr[pos_i+i][pos_j+j]=5;
                        else if(display[i][j]==2)
                            arr[pos_i+i][pos_j+j]=11;
                        else if(display[i][j]==3)
                            arr[pos_i+i][pos_j+j]=15;
                    }
                }
                else
                    arr[pos_i+i][pos_j+j]=0;
            }
        }
    }
    else if(type=="Turnaround")
    {
        int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,0,0,0,1,1,1,1,
						   1,1,0,1,0,1,0,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,0,1,0,1,0,1,1,1,
						   1,1,1,0,0,0,1,1,1,1,
						   1,1,1,1,0,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(display[i][j])
                {
                    if(color=="blue")
                        arr[pos_i+i][pos_j+j]=2;
                    else if(color=="red")
                        arr[pos_i+i][pos_j+j]=3;
                    else if(color=="yellow")
                        arr[pos_i+i][pos_j+j]=4;
                    else if(color=="green")
                        arr[pos_i+i][pos_j+j]=5;
                }
                else
                    arr[pos_i+i][pos_j+j]=0;
            }
        }
    }
    else if(type=="SelectColor")
    {
        int display[15][10]={1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,0,1,2,1,1,1,1,
						   1,1,0,0,1,2,2,1,1,1,
						   1,0,0,0,1,2,2,2,1,1,
						   1,0,0,0,1,2,2,2,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,3,3,3,1,4,4,4,1,1,
						   1,3,3,3,1,4,4,4,1,1,
						   1,1,3,3,1,4,4,1,1,1,
						   1,1,1,3,1,4,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1,
						   1,1,1,1,1,1,1,1,1,1};
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(display[i][j]==0)
                    arr[pos_i+i][pos_j+j]=5;
                else if(display[i][j]==1)
                    arr[pos_i+i][pos_j+j]=1;
                else if(display[i][j]==2)
                    arr[pos_i+i][pos_j+j]=4;
                else if(display[i][j]==3)
                    arr[pos_i+i][pos_j+j]=2;
                else if(display[i][j]==4)
                    arr[pos_i+i][pos_j+j]=3;
            }
        }
    }
    else if(type=="Almighty")
    {
        int display[15][10]={
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,7,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,2,2,1,1,1,1},
			{1,1,1,1,2,2,1,1,1,1},
			{1,1,1,1,2,2,1,1,1,1},
			{1,1,3,3,1,1,5,5,1,1},
			{1,1,3,3,1,1,5,5,1,1},
			{1,1,3,3,1,1,5,5,1,1},
			{1,1,1,1,4,4,1,1,1,1},
			{1,1,1,1,4,4,1,1,1,1},
		    {1,1,1,1,4,4,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
		    {1,1,1,1,1,1,1,1,1,1}
        };
        for(int i=0;i<15;i++)
            for(int j=0;j<10;j++)
                arr[pos_i+i][pos_j+j]=display[i][j];
    }
}
#endif
