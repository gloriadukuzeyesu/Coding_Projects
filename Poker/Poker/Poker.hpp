
#pragma once
#include<string>
#include<vector>

//list struct
struct Card {
    int rank;
    std::string suit;
};

std::vector<Card> CreateDeck();

void PrintDeck(std::vector<Card> DeckOfCards);
void Shuffle(std::vector<Card>& DeckOfCards);
bool isStraight(std::vector<Card>& DeckOfCards);
bool isFlush(const std::vector<Card>& listOfCards);
bool isStraightFlush(std::vector<Card> &DeckOfCards);
bool isRoyalFlush(std::vector<Card>& DeckOfCards);
bool isFullHouse (std::vector<Card> DeckOfCards);
bool CompareCards(const Card& card1, const Card& card2);











