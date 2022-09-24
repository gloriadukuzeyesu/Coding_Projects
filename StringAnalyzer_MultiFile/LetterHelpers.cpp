

#include "iostream"
#include "LetterHelpers.hpp"
//#include "LetterHelpersStrings.h"
using namespace std;

bool isSpace(char c)
{
    return  (c == ' ');
}

bool IsPunctuation(char c){
    return(c==','||c=='?'||c=='!' || c=='.');
}
bool IsVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'||c=='A'||c=='E'||
            c=='I'|| c=='O'|| c=='Y' || c=='U');
}
bool IsConsonant(char c){
    return !IsPunctuation(c) && !IsVowel(c) && c!=' ';
}






