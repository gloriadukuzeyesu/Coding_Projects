//
//  main.cpp
//  Palindromes
//
//  Created by Gloria Dukuzeyesu on 8/25/22.
//

#include <iostream>
#include<string>
using namespace std;


int main(int argc, const char * argv[]) {
    // Group members: Gloria
    //Part1
    //declaration of variables
    string userInput;
    string reversed;
    //prompt the user to enter a word
    cout<<"Enter a word: "<<endl;
    cin>>userInput;
    //build the reversed string one character at time
    for (char i= userInput.length()-1; i>=0; i--) {
        reversed += userInput[i];
    }
    if (reversed == userInput) {
        cout<< userInput <<" IS a palindrome"<<endl;
    }
    else{
        cout<< userInput <<" is NOT palindrome"<<endl;
    }
    return 0;
}
