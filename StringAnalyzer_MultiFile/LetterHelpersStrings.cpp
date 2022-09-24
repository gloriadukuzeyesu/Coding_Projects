
#include <iostream>
#include <string>
#include "LetterHelpersStrings.h"
#include "LetterHelpers.hpp"

using namespace std;
//fx() that return number of words
int NumWords(string s){
    int counter=1;
    for (int i=0; i<=s.length(); i++) {
        if (isSpace(s[i])) {
            counter++;
        }
    }
        if(s.length() > 0)
            return counter;
        else
            return 0;
}
// fx() that returns number of sentence in a string
int NumSentences(string s){
    int sentences =0;
    for (int i=0; i<=s.length(); i++) {
        if (IsPunctuation(s[i])) {
            sentences++;
        }
    }return sentences;
}
int NumVowels(string s){
    int vowels=0;
    for (int i=0; i<=s.length(); i++) {
        if (IsVowel(s[i])) {
            vowels++;
        }
    }return vowels;
}
//fx() that the number of consonants in the string
int NumConsonants(string s){
    int consonants=0;
    for (int i=0; i<s.length(); i++) {
        if (IsConsonant(s[i])) {
            consonants++;
//            cout<<s[i]<<" ";
        }
    }return consonants;
}
double AverageWordLength(string s){
    double Average = ((double)NumVowels(s) + (double)NumConsonants(s))/(double)NumWords(s);
//    cout<<NumVowels(s)<<"  "<<NumConsonants(s)<<endl;
    return Average;
}
double AverageVowelsPerWord(string s){
    double AverageVowelPerWord = (double)NumVowels(s)/ (double)NumWords(s);
    return AverageVowelPerWord;
}

