#include <iostream>
#include <string>
#include <stdexcept>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "Player.h"
#include "Card.h"
using namespace std;

void initialCardStack();
void shuffle(LinkedStack<Card>&);
void draw_card(LinkedStack<Card>&,Player);
bool Nobody_win(LinkedQueue<Player>&);
void refill(LinkedStack<Card>&,LinkedStack<Card>&);

int main()
{
    LinkedQueue<Player> Player_list;
    int player_num;
    //輸入玩家數目
    cin>>player_num;
    //輸入玩家名稱
    for(int i=0;i<player_num;i++)
    {
        string name;
        getline(cin,name);
        Player temp(name);
        Player_list.enqueue(temp);
    }
    //牌堆
    LinkedStack<Card> CardStack;
    //把108張牌加進牌堆
    initialCardStack();
    //洗牌
    shuffle(CardStack);
    //每位玩家抽5張牌
    for(int i=0;i<player_num;i++)
    {
        Player temp=Player_list.peekFront();
        for(int j=0;j<5;j++)
            draw_card(CardStack,temp);
        Player_list.dequeue();
        Player_list.enqueue(temp);
    }
    LinkedStack<Card> usedCard;
    //遊戲開始
    while(Nobody_win(Player_list))
    {
        //牌局目前的顏色和數字
        string current_color="none";
        int current_number=-1;

        if(CardStack.isEmpty())
            refill(CardStack,usedCard);
        Player current_player=Player_list.peekFront();
        //顯示當前玩家所有的牌
        current_player.display_all();

        cout<<"\n"<<"你要出哪一張牌？"<<"\n\n"<<"抽牌請按 d"<<;
        string s;
        int valid=0,n;
        while(!valid)
        {
            try
            {
                getline(cin,s);
                if(s.compare("d"))
                {
                    draw_card(CardStack,current_player);
                    valid=1;
                }
                n=stoi(s);
                if(n>0&&n<=current_player.get_card_count())
                    valid=2;
                else
                    throw runtime_error(s);
            }
            catch(runtime_error r)
            {
                cout<<"你不能輸入";
                cout<<" "<<r.what()<<endl;
                cout<<"如果沒牌請按 d"<<endl;
            }
        }
        if(valid==1)
            continue;
        //取得玩家出的那張牌
        Card used=current_player.use_card(n);
        //以下開使判定這是什麼卡，然後做操作
    }

    //遊戲結束，看要印出什麼東西都可以

    return 0;
}
