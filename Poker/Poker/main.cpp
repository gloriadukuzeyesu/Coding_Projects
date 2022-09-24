#include"Poker.hpp"
#include <iostream>
#include <string>
#include<vector>
#include <cassert>

//never include a .cpp file in main

using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL)); // srand() creates a giant list of cards. each time you call rand() it grabs a random number from that giant list
    
    //Test for Create Function
   
    
    //create a deck of random five cards
    //create a loop and set a variable counter that will count everytime a f() returns true
    //keep updating the counter as you go
    //at the end divide the counter to the number of times you loop
    //to find out the probality of getting each function
    // in your if statement start from the least possible f() that full house
    
    vector<Card> deck = CreateDeck();
    assert(deck.size() == 52);
//    int counter = 0;
//    int maxCounter = 10000;
    Shuffle(deck);
    
//    vector <Card> mainHand =
//    {
//        deck[0];
//        deck[1];
//        deck[2];
//        deck[3];
//        deck[4];
//    };

    
    
    

    
    
    
    
    
    
    
    //initialization of card
    Card card0 = {10, "10"};
    Card card1 = {11, "Ace"};
    Card card2 = {12, "Jack"};
    Card card3 = {13, "Queen"};
    Card card4 = {14, "King"};

    vector<Card> hand; // hand holds a vector of cards
    hand.push_back(card0);
    hand.push_back(card1);
    hand.push_back(card2);
    hand.push_back(card3);
    hand.push_back(card4);

    
    //Test for Shuffle()
    
    //Test for PrintDeck()
//    PrintDeck(deck);
    
    //Text for isFlush()
    vector<Card> hand1;
    Card card5 = {2, "Diamonds"};
    Card card6 = {3, "Diamonds"};
    Card card7 = {4, "Diamonds"};
    Card card8 = {5, "Diamonds"};
    Card card9 = {6, "Diamonds"};
    hand1.push_back(card5);
    hand1.push_back(card6);
    hand1.push_back(card7);
    hand1.push_back(card8);
    hand1.push_back(card9);
    
    PrintDeck(hand1);
    
    if (isFlush(hand1))
        cout<< "It is a flush" <<endl;
    else
        cout<< "Not a flush" <<endl;
    
    
    //Test for isStraight()
    if (isStraight(hand1))
        cout << "It is Straight" << endl;
    else
        cout << "Not Straight" << endl;
    
    
    //Test for isStraightFlush
    if (isStraightFlush(hand1))
        cout << "It is Straight Flush" << endl;
    else
        cout << "Not Straight Flush" << endl;
    
//
//    //Test for isRoyalFlush
    
    if (isRoyalFlush(hand))
        cout << "It is Royal Flush" << endl;
    else
        cout << "Not Royal Flush" << endl;
    
   

    //Test for isFullHouse
    
    vector<Card> Hand3;
    Card card10 = {3, "Hearts"};
    Card card11 = {3, "Clubs"};
    Card card12 = {3, "Diamonds"};
    Card card13 = {2, "Hearts"};
    Card card14 = {2, "Diamonds"};
    
    Hand3.push_back(card10);
    Hand3.push_back(card11);
    Hand3.push_back(card12);
    Hand3.push_back(card13);
    Hand3.push_back(card14);

    
    if (isFullHouse(Hand3))
        cout << "It is a full house" << endl;
    else
        cout << "Not a Full House" << endl;

    return 0;
}
