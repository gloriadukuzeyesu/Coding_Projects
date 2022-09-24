
#include <iostream>
#include <string>
#include<vector>
#include"DeckOfCards.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<Card> deck = CreateDeck();
    assert(deck.size() == 52);

    PrintDeck(deck);
    
    return 0;
}
