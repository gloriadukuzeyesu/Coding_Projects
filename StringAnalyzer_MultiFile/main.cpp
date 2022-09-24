
#include <iostream>
#include "LetterHelpers.hpp"
#include "LetterHelpersStrings.h"
using namespace std;

int main(int argc, const char * argv[]) {
    string userInput;
    do {
        cout<<"Enter a string containing one or more sentences: "<<endl;
        getline(cin,userInput); //takes in whole line from userInput
        if (userInput == "done") {
            cout<<"Goodbye"<<endl;
            break;
        }
        cout<<"Analysis: "<<endl<<" Number of words: "<<NumWords(userInput)<<endl;
        cout<<" Number sentences: "<<NumSentences(userInput)<<endl;
        cout<<" Number of vowels: "<<NumVowels(userInput)<<endl;
        cout<<" Number of Consonants: "<<NumConsonants(userInput)<<endl;
        cout<<" Average Word Length is: "<<AverageWordLength(userInput)<<endl;
        cout<<" Average vowels per word: "<<AverageVowelsPerWord(userInput)<<endl;
    }
    while (userInput != "done");
    return 0;
}
