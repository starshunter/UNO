#include <iostream>
#include <string>
#include <stdexcept>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "Player.h"
#include "Card.h"
#include "unoFunction.h"
using namespace std;

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
    initialCardStack(CardStack);
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
    //用過的牌
    LinkedStack<Card> usedCard;
    //遊戲開始
    while(Nobody_win(Player_list,player_num))
    {
        //牌堆已經沒有牌了
        if(CardStack.isEmpty())
        {
            while(!usedCard.isEmpty())
            {
                CardStack.push(usedCard.peek());
                usedCard.pop();
            }
            shuffle(CardStack);
        }

        //牌局目前的顏色和數字
        string current_color="none";
        int current_number=-1;

        if(CardStack.isEmpty())
            refill(CardStack,usedCard);
        Player current_player=Player_list.peekFront();
        //顯示當前玩家所有的牌
        current_player.display_all();

        cout<<"\n"<<"你要出哪一張牌？"<<"\n\n"<<"抽牌請按 d";
        string s;
        int valid=0,n;
        while(!valid)
        {
            try
            {
                getline(cin,s);
                if(!s.compare("d"))
                {
                    draw_card(CardStack,current_player);
                    valid=1;
                }
                n=stoi(s);
                if(n>0&&n<=current_player.get_card_count())
                {
                    Card temp=current_player.use_card(n);
                    if(!able_to_use(temp,current_color,current_number))
                        throw runtime_error(s);
                    valid=2;
                }
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
        current_player.remove_card(n);
        //以下開使判定這是什麼卡，然後做操作
        string card_type=used.get_type();
        if(!card_type.compare("Normal"))
        {
            current_color = used.get_color();
            current_number = used.get_number();
            Player_list.enqueue(current_player);
            usedCard.push(used);
        }
        else if(!card_type.compare("Forbidden"))
        {
            Player_list.enqueue(current_player);               //ß‚§H•·®Ï´·≠±(∑Ì´e™±Æa)
            Player temp=Player_list.peekFront();
    	    Player_list.enqueue(temp);               //ß‚§H•·®Ï´·≠±(§U§@¶Ï™±Æa)
            Player_list.dequeue();
            usedCard.push(used);
        }
        else if(!card_type.compare("Turnaround"))
        {
            LinkedStack<Player> tempPlayerStack;
        	while(!Player_list.isEmpty())                                    //≥–§@≠”temp stack•·∂i•h
			{
                Player temp=Player_list.peekFront();
	            tempPlayerStack.push(temp);
	            Player_list.dequeue();
			}
           	while(!tempPlayerStack.isEmpty())                                    //±qtemp stack•·¶^®”(∂∂ß«ßY¨€§œ)
			{
                Player temp=Player_list.peekFront();
	            Player_list.enqueue(temp);
	            tempPlayerStack.pop();
			}
			Player_list.enqueue(current_player);
            usedCard.push(used);
        }
        else if(!card_type.compare("Add"))
        {
            Player_list.enqueue(current_player);               //§w™±πL
            Player temp = Player_list.peekFront();
            for(int i=0;i<2;i++)
            {
                if(CardStack.isEmpty())
                    refill(CardStack,usedCard);
                draw_card(CardStack,temp);
            }
            usedCard.push(used);
        }
        else if(!card_type.compare("SelectColor"))
        {
            cout<<"請選擇顏色(red,green,yellow,blue)"<<"\n\n";
            string s;
            bool flag=false;
            
            while(!flag)
            {
                try
                {
                    getline(cin,s);
                    if(!s.compare("red")||!s.compare("green")||!s.compare("yellow")||!s.compare("blue"))
                        flag=true;
                    else
                        throw runtime_error(s);
                }
                catch(runtime_error r)
                {
                    cout<<"請輸入一種顏色(red,green,yellow,blue)"<<"\n";
                }
            }

            current_color=s;
            usedCard.push(used);
        }
        else if(!card_type.compare("Almighty"))
        {
            cout<<"請選擇顏色(red,green,yellow,blue)"<<"\n\n";
            string s;
            bool flag=false;

            while(!flag)
            {
                try
                {
                    getline(cin,s);
                    if(!s.compare("red")||!s.compare("green")||!s.compare("yellow")||!s.compare("blue"))
                        flag=true;
                    else
                        throw runtime_error(s);
                }
                catch(runtime_error r)
                {
                    cout<<"請輸入一種顏色(red,green,yellow,blue)"<<"\n";
                }
            }

            current_color=s;
            Player_list.enqueue(current_player);               //§w™±πL
            Player temp = Player_list.peekFront();
            for(int i=0;i<4;i++)
            {
                if(CardStack.isEmpty())
                    refill(CardStack,usedCard);
                draw_card(CardStack,temp);
            }

            usedCard.push(used);
        }
    }
    return 0;
}
