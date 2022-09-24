
#include "DeckOfCards.hpp"
#include <iostream>
#include <vector>
#include <string>
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


void PrintDeck(vector<Card> DeckOfCards)
{
    for( Card oneCard : DeckOfCards)
    {
        cout<<oneCard.rank<<" of "<<oneCard.suit<<endl;
    }
}




