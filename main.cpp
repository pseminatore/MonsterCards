#include <iostream>
#include "NumberLinkedList.h"
#include "MonsterCard.h"
#include "StackClass.h"
#include "dyncardqueue.h"
#include "Player.h"
#include <stdlib.h>

using namespace std;

    void addCards(Player& player1, Player& player2) {
        int opt;

        while (true){

            cout<<"Which Player would like to add cards to their deck?"<<endl;
            cin>>opt;

            if (opt==1){
                player1.fillDeck();
                return;
            } else if (opt == 2){
                player2.fillDeck();
                return;

            }
            else{
            cout<<"Error: Invalid Input"<<endl;
            }
        }
    }

    void  tradeTopCards(Player& player1, Player& player2) {

        MonsterCard tempCard1;
        MonsterCard tempCard2;

        tempCard1 = player1.tradeFromDeck(tempCard1);
        tempCard2 = player2.tradeFromDeck(tempCard2);

        cout<<"Player 1 traded: "<<tempCard1.Getname()<<endl;
        cout<<"Player 2 traded: "<<tempCard2.Getname()<<endl;

        player1.recieveToDeck(tempCard2);
        player2.recieveToDeck(tempCard1);
    }

    void battle(Player& player1, Player& player2) {

        MonsterCard activePlayer1;
        MonsterCard activePlayer2;

        int turn;
        int battleTurn;

        // draw cards
        for (int i = 0; i<5; i++){
          player1.drawCard(i);
          player2.drawCard(i);
        }

        //each player starts with 8000 life points
        player1.SetlifePoints(8000);
        player2.SetlifePoints(8000);

        //flip coin to see who goes first
        turn = rand() %2 + 1;
        cout<<"Player "<<turn<<" goes first!"<<endl;

        //loop until someone runs out of health
        while (player1.GetlifePoints()>0 && player2.GetlifePoints()>0){

            //Player 1's turn
            battleTurn = turn;
            int total = 0;
            int indexA;
            int indexD;

            while (total <2){

                if (turn == 1){
                    cout<<""<<endl;
                    cout<<"Player 1's turn!"<<endl;

                    player1.displayHand();

                    cout<<"Please input the card number you'd like to play in attack mode: ";
                    cin>>indexA;

                    player1.hand[indexA].setAttackPosition(true);
                    player1.attackQueue.enqueue(player1.hand[indexA]);

                    cout<<"Please input the card number you'd like to play in defense mode: ";
                    cin>>indexD;

                    player1.hand[indexD].setAttackPosition(false);
                    player1.defenseQueue.enqueue(player1.hand[indexD]);

                    turn++;
                    total++;

                    if (!player1.deckEmpty()) {
                        player1.drawCard(indexA);
                        player1.drawCard(indexD);
                    } 
                    else {
                        MonsterCard card;
                        player1.hand[indexA] = card;
                        player1.hand[indexD] = card;
                    }


                } else if (turn==2) {

                    cout<<""<<endl;
                    cout <<"Player 2's turn!"<<endl;
                    player2.displayHand();

                    cout<<"Please input the card number you'd like to play in attack mode: ";
                    cin>>indexA;

                    player2.hand[indexA].setAttackPosition(true);
                    player2.attackQueue.enqueue(player2.hand[indexA]);

                    cout<<"Please input the card number you'd like to play in defense mode: ";
                    cin>>indexD;

                    player2.hand[indexD].setAttackPosition(false);
                    player2.defenseQueue.enqueue(player2.hand[indexD]);

                    turn--;
                    total++;

                    if (!player2.deckEmpty()){
                        player2.drawCard(indexA);
                        player2.drawCard(indexD);

                    } else {
                        MonsterCard card;
                        player2.hand[indexA] = card;
                        player2.hand[indexD] = card;
                    }

                }
            }


            //battle phase
            total = 0;
            while (total < 2){

                int choice;
                cout<<"Battle Phase!"<<endl;

                if (battleTurn==1){

                    cout<<"Player 1: input 1 for attack or 2 for defense: ";
                    cin >> choice;

                    if (choice == 1) {
                        activePlayer1= player1.attackQueue.dequeue(activePlayer1);
                    } else if (choice == 2) {
                        activePlayer1=player1.defenseQueue.dequeue(activePlayer1);
                    } else {
                        cout<<"Error: invalid input"<<endl;
                    }
                    battleTurn = 2;

                } else if (battleTurn==2) {

                    cout<<"Player 2: input 1 for attack or 2 for defense: ";
                    cin >> choice;

                    if (choice == 1) {
                        activePlayer2=player2.attackQueue.dequeue(activePlayer2);
                    } else if (choice == 2) {
                        activePlayer2=player2.defenseQueue.dequeue(activePlayer2);
                    } else {
                        cout<<"Error: invalid input"<<endl;
                    }
                    battleTurn = 1;

                }
                total++;
            }

            //compare values
            if (activePlayer1.getAttackPosition()){

                cout<<"Player 1 chose ATK!"<<endl;

                if (activePlayer2.getAttackPosition()) {

                    cout<<"Player 2 chose ATK!"<<endl;

                    if ((activePlayer1.GetattackPoints()) > (activePlayer2.GetattackPoints())) {

                        player2.SetlifePoints((player2.GetlifePoints()-(activePlayer1.GetattackPoints()-activePlayer2.GetattackPoints())));

                        cout<<"Player 2 took "<<(activePlayer1.GetattackPoints()-activePlayer2.GetattackPoints())<<" damage."<<endl;

                    } else if (activePlayer2.GetattackPoints() > activePlayer1.GetattackPoints()) {

                        player1.SetlifePoints((player1.GetlifePoints()-(activePlayer2.GetattackPoints()-activePlayer1.GetattackPoints())));

                        cout<<"Player 1 took "<<(activePlayer2.GetattackPoints()-activePlayer1.GetattackPoints())<<" damage."<<endl;

                    } 

                } else if (!activePlayer2.getAttackPosition()){

                    cout<<"Player 2 chose DEF!"<<endl;

                    if (activePlayer1.GetattackPoints()>activePlayer2.GetdefensePoints()) {

                        player2.SetlifePoints(player2.GetlifePoints()-(activePlayer1.GetattackPoints()-activePlayer2.GetdefensePoints()));

                        cout<<"Player 2 took "<<activePlayer1.GetattackPoints()-activePlayer2.GetdefensePoints()<<" damage."<<endl;

                    }else {

                        cout <<"Player 2 took 0 damage."<<endl;

                    }
                }
            }else if (!activePlayer1.getAttackPosition()) {

                cout<<"Player 1 chose DEF!"<<endl;

                if (activePlayer2.getAttackPosition()){

                    cout<<"Player 2 chose ATK!"<<endl;

                    if (activePlayer2.GetattackPoints()>activePlayer1.GetdefensePoints()){

                        player1.SetlifePoints(player1.GetlifePoints()-(activePlayer2.GetattackPoints()-activePlayer1.GetdefensePoints()));

                        cout<<"Player 1 took "<<activePlayer2.GetattackPoints()-activePlayer1.GetdefensePoints()<<" damage."<<endl;

                    } else {

                        cout <<"Player 1 took 0 damage."<<endl;

                    }
                } else if (!activePlayer2.getAttackPosition()){

                    cout<<"Player 2 chose DEF!"<<endl;
                    cout<<"Both chose defense.  Discard cards."<<endl;

                }
            }

            cout<<"Player 1 LifePoints: "<<player1.GetlifePoints()<<endl;
            cout<<"Player 2 LifePoints: "<<player2.GetlifePoints()<<endl;
        }

        cout<<"battle complete"<<endl;
    }

    int main() {
        Player player1;

        cout<<"*****You must enter at least 5 cards in order to play*****"<<endl;

        player1.fillDeck();

        Player player2;

        cout<<"*****You must enter at least 5 cards in order to play*****"<<endl;

        player2.fillDeck();

        int option;

        while (true) {

            option = 0;

            cout<<""<<endl;
            cout<<"---------------------------------------------------------------------------------------"<<endl;
            cout<<"Choose an option from below: "<<endl;
            cout<<"1. Add Cards to a Deck"<<endl;
            cout<<"2. Trade Top Cards"<<endl;
            cout<<"3. Battle!"<<endl;
            cout<<"4. Quit..."<<endl;
            cin>> option;
            cout<<""<<endl;

            if (option == 1) {

                addCards(player1, player2);

            } else if (option ==2) {

                tradeTopCards(player1, player2);

            } else if (option ==3) {

                battle(player1, player2);

            } else if (option ==4) 
            {
                exit(0);

            } else {

                cout<<"Invalid choice.  Try again!"<<endl;

            }

        }

        return 0;
}


