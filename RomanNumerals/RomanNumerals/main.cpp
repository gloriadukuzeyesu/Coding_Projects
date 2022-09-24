
#include <iostream>
#include <string>
using namespace std;


//create a fx() that will convert int into roman numerals

string integerToRoman(double x){
    //create an array of tokens
    string romansToken[]={"M", "CM", "D","CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    //create an array of values corresponding to romanTokens
    int values[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    //container of the resuls
    string result="";
    
    //use loop to to apply the largest Roman Numeral token, then subtract the value of that token from the remaining decimal number, and repeat
   
    if (x<=0) {
        cout<<"Entered Invalid Number"<<endl;
    }
    else{
        for (int i=0; i<13; ++i) {
            while (x-values[i] >=0) {
                result= result + romansToken[i];
                x= x-values[i];
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    double UserInputNumber;
    cout<<"Enter decimal number: "<<endl;
    cin>>UserInputNumber;
    cout<<"Roman numeral version: "<<integerToRoman(UserInputNumber)<<endl;
    
    
    return 0;
}
