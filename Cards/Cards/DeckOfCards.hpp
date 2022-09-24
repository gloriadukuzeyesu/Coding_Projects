
#pragma once
#include<string>
#include<vector>

//list of functions and struct
struct Card{
    int rank;
    std::string suit;
};

std::vector<Card> CreateDeck();
void PrintDeck(std::vector<Card> DeckOfCards);






