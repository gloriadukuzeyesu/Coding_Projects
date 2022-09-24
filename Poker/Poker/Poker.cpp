
#include "Poker.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "time.h"
//#include <bits/stdc++.h>

using namespace std;

vector<Card> CreateDeck(){
    vector<Card> Deck; // a deck of cards
    vector<string> suits = {"diamonds", "spades","clubs","hearts"};
    for(int i=0; i<4; i++){
        for(int x=1; x<14;x++)
        {
         Card paper;
            paper.rank= x;
            paper.suit = suits[i];
            Deck.push_back(paper);
            
            assert(paper.rank == x && (paper.suit.compare(suits[i]) == 0));
        }
    }
    return Deck;
};


//function to compare rank and suit for the cards next to each other
bool CompareCards(const Card& card1, const Card& card2)
{
    return (card1.rank<card2.rank);
}


// function that prints the deck
void PrintDeck(vector<Card> DeckOfCards)
{
    for( Card oneCard : DeckOfCards)
    {
        cout<<oneCard.rank<<" of "<<oneCard.suit<<endl;
    }
}

// shuffle f() will rearrange/shuffle the deck
void Shuffle(vector<Card>& DeckOfCards){
    for (int i=0; i<DeckOfCards.size(); i++) {
        //Random picking up a position
        int j =  rand()% 52;
        // swap () will swap the randomly chosen element from the range 0 to 51
        swap(DeckOfCards[i], DeckOfCards[j]);
    }
}

//five card of the same suit in the order
bool isFlush(const vector<Card>& listOfCards)
{
    for (int i=0; i<listOfCards.size()-1; i++)
    {
        if (listOfCards[i].suit != listOfCards[i+1].suit)
        {
            return false;
        }
            
    }
    return true;
}

// isStraight f(x) to see if all five cards are in a sequence( numerical order)
// sort cards by ranks
bool isStraight(vector<Card>& DeckOfCards){
    sort(DeckOfCards.begin(), DeckOfCards.end(), CompareCards);
    Card card = DeckOfCards[0];
    for (int i=1; i < DeckOfCards.size(); i++) {
        if (DeckOfCards[i].rank != card.rank + 1 ) {
            return false;
        }
        card = DeckOfCards[i];
    }
    return true;
}

// isStraightFlush returns true if isflush and isStraight is true. five cards in sequential order of the same suit
bool isStraightFlush(vector<Card>& DeckOfCards){
    if (isFlush(DeckOfCards) && isStraight(DeckOfCards)){
        return true;
    }
    return false;
}

//isRoyalFlush: is this hand a straight flush whose low card is a ten? 10,J,Q,K,A
//the user has 5 cards. the lowest is 10 and the highest in 14. user has to have them arranged in order.

bool isRoyalFlush(vector<Card>& DeckOfCards){
    sort(DeckOfCards.begin(), DeckOfCards.end(), CompareCards);
    Card lowcard = DeckOfCards[0];
    if (isStraight(DeckOfCards) && lowcard.rank == 10 && isFlush(DeckOfCards)){
        return true;
    }
    else
        return false;
}

//contains three cards of one rank and two cards of another rank,

bool isFullHouse (vector<Card> DeckOfCards){
    //find the position of the starting of secong group
    // two posible option. 1st when two pairs, three kinds
    // 2nd option, three kinds, two pairs
    sort(DeckOfCards.begin(), DeckOfCards.end(), CompareCards);
    int pos;
    if (DeckOfCards[1].rank != DeckOfCards[2].rank) {
        //if card's rank at position 1 is equal to card's rank at position 2, pos=3 otherwise pos=2
        pos = 2;
    } else {
        pos = 3;
    }
    // For option1, three kinds front, two pairs back
    for (int i=0; i< pos - 1; i++) {
//        cout <<"card-" << i << " rank:" << DeckOfCards[i].rank << endl;
//        cout <<"card-" << i + 1 << " ran:" << DeckOfCards[i+1].rank << endl;
//        cout << endl;
        if ( DeckOfCards[i].rank != DeckOfCards[i+1].rank ) {
            return false;
        }
    }
    cout << endl;
    //for Option2 three of same kinds in front and two pairs after
    for (int i=pos; i < DeckOfCards.size() - 1 ; i++) {
        if (DeckOfCards[i].rank != DeckOfCards[i+1].rank) {
            return false;
        }
    }
    return true;
}




