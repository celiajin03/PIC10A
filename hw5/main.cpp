//  Chen Jin
//  PIC10A hw5
//  2018/5/7
//  The program simulates the casino game blackjack. It draws randoms numbers to represent cards drawn for players and dealers, and determines the results through the game.

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

double draw_card(int total, string &card)
{
    int rank=1+rand()%13;
    int suite=1+rand()%4;
    string card_rank;
    string card_suite;
    
    //defining each random number to represent a card
    if (rank==1)
        card_rank="Ace of ";
    if (rank==2)
        card_rank="Two of ";
    if (rank==3)
        card_rank="Three of ";
    if (rank==4)
        card_rank="Four of ";
    if (rank==5)
        card_rank="Five of ";
    if (rank==6)
        card_rank="Six of ";
    if (rank==7)
        card_rank="Seven of ";
    if (rank==8)
        card_rank="Eight of ";
    if (rank==9)
        card_rank="Nine of ";
    if (rank==10)
        card_rank="Ten of ";
    if (rank==11)
        card_rank="Jack of ";
    if (rank==12)
        card_rank="Queen of ";
    if (rank==13)
        card_rank="King of ";
    
    if (suite==1)
        card_suite="clubs";
    if (suite==2)
        card_suite="hearts";
    if (suite==3)
        card_suite="diamonds";
    if (suite==4)
        card_suite="spades";
    
    card=card_rank+card_suite;
    
    if (rank==11 | rank==12 |rank==13)
        return 10;
    else if (rank==1 & total+11<=21)
        return 11;
    else
        return rank;
}



int main()
{
    srand((int)(time(0)));
    int money=100;
    int bet;
    int total_p=0;
    int total_d=0;
    int value;
    string card;
    string yn;
    
    while (money>0 & money<1000)
    {
        //ask user to enter their bet and reenter if the amount exceeds their money owned
        cout<<"You have $"<<money<<". Enter bet: ";
        cin>>bet;
        while (bet>money)
        {
            cout<<"You only have $"<<money<<" to bet. Enter bet: ";
            cin>>bet;
        }
    
        //player's turn for drawing cards
        value = draw_card(total_p, card);
        total_p +=value;
        cout<<endl<<"Your cards are:"<<"\n  "<<card;

        value = draw_card(total_p, card);
        total_p +=value;
        cout<<"\n  "<<card<<endl;
    
        cout<<"Your total is "<<total_p<<".  Do you want another card (y/n)?";
        cin>>yn;
        while (yn=="y" & (total_p<=21))
        {
            int value = draw_card(total_p, card);
            total_p +=value;
            cout<<endl<<"You draw a:"<<"\n  "<<card;
            if (total_p<=21)
            {
                cout<<endl<<"Your total is "<<total_p<<".  Do you want another card (y/n)?";
                cin>>yn;
            }
            else
                cout<<endl<<"Your total is "<<total_p<<".  You busted!"<<endl;
        }
    
        //dealer's turn for drawing cards
        value = draw_card(total_d, card);
        total_d +=value;
        cout<<endl<<"The dealer's cards are:"<<"\n  "<<card;
    
        value = draw_card(total_d, card);
        total_d +=value;
        cout<<"\n  "<<card<<endl;
        cout<<"The dealer's total is "<<total_d<<"."<<endl;
    
        while (total_d<=16)
        {
            value = draw_card(total_d, card);
            total_d +=value;
            cout<<endl<<"The dealer draws a card."<<"\n  "<<card<<endl;
            cout<<"The dealer's total is "<<total_d<<"."<<endl;
        }
    
        //compare final results of total points for player and dealer
        if (total_p<=21 & total_d<=21)
        {
            if (total_p>total_d)
            {
                cout<<"You win $"<<bet<<"!"<<endl<<endl;
                money +=bet;
            }
            if (total_p<total_d)
            {
                cout<<"Too bad.  You lose $"<<bet<<"."<<endl<<endl;
                money -=bet;
            }
            if (total_p==total_d)
                cout<<"A draw! You get back your $"<<bet<<"."<<endl<<endl;
        }
        
        if (total_p<=21 & total_d>21)
        {
            cout<<"You win $"<<bet<<"!"<<endl<<endl;
            money +=bet;
        }
        
        if (total_p>21)
        {
            cout<<"Too bad.  You lose $"<<bet<<"."<<endl<<endl;
            money -=bet;
        }
        
        total_p=0;
        total_d=0;
    
    }
    cout<<"You have $"<<money<<".  GAME OVER."<<endl;
    return 0;
    
}
