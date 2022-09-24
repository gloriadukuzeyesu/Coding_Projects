
#include <iostream>
#include<string>
using namespace std;
bool isSpace(char c)
{
    return  (c == ' ');
}
//bool IsTerminator(char c){
//    return (c==','||c=='?'||c=='!');
//}
bool IsPunctuation(char c){
    return(c==','||c=='?'||c=='!');
}

bool IsVowel(char c){
    return (c=='a'|| c=='e'||c=='i'||c=='o'||c=='u'||c=='y'||
            c=='A'||c=='E'||c=='I'|| c=='O'|| c=='Y' || c=='U');
}
bool IsConsonant(char c){
    return !IsPunctuation(c) && !IsVowel(c) && c!=' ';
}
//fx() that return number of words
int NumWords(string s){
    int counter=1;
    for (int i=0; i<=s.length(); i++) {
        if (isSpace(s[i])) {
            counter++;
        }
    }    return counter;
}
// fx() that returns number of sentence in a string
int NumSentences(string s){
    int sentences =0;
    for (int i=0; i<s.length(); i++) {
        if (IsPunctuation(s[i])) {
            sentences++;
        }
    }return sentences;
}
//fx() that returns number of vowels
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
    for (int i=0; i<=s.length(); i++) {
        if (IsConsonant(s[i])) {
            consonants++;
//            cout<<s[i]<<" ";
        }
    }return consonants;
}
//Returns the average length of all words in the string.
double AverageWordLength(string s){
    double Average = ((double)NumVowels(s) + (double)NumConsonants(s))/(double)NumWords(s);
    return Average;
}
//f() Returns the average number of vowels per word in the string
double AverageVowelsPerWord(string s){
    double AverageVowelPerWord = (double)NumVowels(s)/ (double)NumWords(s);
    return AverageVowelPerWord;
}
int main(int argc, const char * argv[]) {
    string userInput;
    do {
        cout<<"Enter a string containing one or more sentences: "<<endl;
        getline(cin,userInput);
        if (userInput == "done") {
            cout<<"Goodbye"<<endl;
            break;
        }
        cout<<"Analysis: "<<endl<<"Number of words: "<<NumWords(userInput)<<endl;
        cout<<"Number sentences: "<<NumSentences(userInput)<<endl;
        cout<<"Number of vowels: "<<NumVowels(userInput)<<endl;
        cout<<"Number of Consonants: "<<NumConsonants(userInput)<<endl;
        cout<<"Average is: "<<AverageWordLength(userInput)<<endl;
        cout<<"Average vowels per word: "<<AverageVowelsPerWord(userInput)<<endl;
    }
    while (userInput != "done");
        return 0;
}
