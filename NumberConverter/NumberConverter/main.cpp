
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


//function that convert decimal number in string form to the integer form of the same number

int stringToInt( string MyString,int x){ // int to decimal
    int numericValue = 0;
    
    if ( x== 10) {
        numericValue = stoi(MyString) - 0;
    }else if( x == 2){ //binary to decimal
        int n;
        int remainder = 0;
        int i=0;
        n = stoi(MyString);
        
        while (n!=0) {
            remainder = n % 10;
            n = n / 10;
            numericValue = numericValue + remainder * pow(2,i);
            i++;
        }
    }else if (x == 16){ // hex to decimal
        int stringlength = (int) MyString.size();
        
        //initialize the base value 16^0 to 1
        int base = 1;
        for (int i = stringlength - 1; i>=0; i--) {
            if (MyString[i] > '0' && MyString[i] <= '9') {
                numericValue = numericValue + ( int (MyString[i]) - 48) * base;
                
                //then increment the base by power
                base = base * 16;
                
                
                // find a way this f() take can work with
            }else if( (MyString[i] >= 'A' && MyString[i]<= 'F') ){
                
                numericValue = numericValue + (int (MyString[i]) - 55) * base;
                base = base * 16;
                
            } else if ((MyString[i] >= 'a' && MyString[i]<= 'f') ){
                numericValue = numericValue + (int (MyString[i]) - 87) * base;
                base = base * 16;
            }
        }
    }
    
    return numericValue;
}

//Part 2
//Convert an int to its decimal representation as a string
string inToItsDecimal (int x){
    string decimalValue;
    char character;
    character = x + '0';
//    append the character to the end of the string
    decimalValue = decimalValue + character;
    return decimalValue;
}

//Convert an int to its binary string representation
string IntToBinary ( int x ){
    // create a vector that will store the binary value
    vector<int> VectorOfRemainders;
    
    // divide the number with 2 and store the remainder a vector of remainders
    while (x > 0) {
        int remainder;
        remainder = x % 2;
//        cout << "remainder is " << remainder << " ";
        x = x/2;
        VectorOfRemainders.push_back(remainder);
    }
    
    //print the string vector in a reverse order and concatenate the strings
    string BinaryValue;
    for (long j = VectorOfRemainders.size() -1; j >=0; j--) {
        BinaryValue = BinaryValue + to_string(VectorOfRemainders[j]);
    }
    return BinaryValue;
}

//Convert an int to its hexadecimal string representation
string intToHexadecimal ( int x ) {
    // create a vector that will store the hexvalues
    vector<string> VectorOfRemainders;
    
    // divide the number with 16 and and keep the remainders. if the remainder is less than 10, add it to 48/ 'a' and store its chars value
    // into vector. if it's greater than 10, add it to 55 and store its corresponding char value into the vector
    while ( x != 0){
        int remainder;
        remainder = x % 16;
        string c;
        
        if (remainder < 10) {
             c = to_string(remainder);
        }
        else if( remainder == 10){
            c = "A";
        }else if (remainder == 11){
            c = "B";
        }else if (remainder == 12){
            c = "C";
        }else if (remainder == 13){
            c = "D";
        }else if (remainder == 14){
            c = "E";
        }else if (remainder == 15){
            c = "F";
        }
            
    VectorOfRemainders.push_back(c);

        x = x / 16;
    }

    string hexavalue;

    //print the vector of remainders in a reverse order and concatenate the strings
    for (long i= VectorOfRemainders.size() - 1; i >= 0; i--) {
        hexavalue = hexavalue + VectorOfRemainders[i];
    }

    return hexavalue;
}






using namespace std;

int main(int argc, const char * argv[]) {
//    part 1
    string myBinary = "111";
    string mydec = "9";
    string myhex = "FF";
    int x = 2;
    int y = 10;
    int z = 16;

    cout << stringToInt(myBinary, x) << endl;
    cout << stringToInt(mydec, y) << endl;
    cout << stringToInt(myhex, z) << endl;
    
    //Part 2
//    int m = 9;
//    cout << inToItsDecimal(m) << endl;
    
    int k = 15;
    cout << "the binary value is: " << IntToBinary(k) << endl;
    
    int n= 255;
    cout << "The Hexadecimal value is: " << intToHexadecimal(n) << endl;
    
    cout << stringToInt(intToHexadecimal(n), z) << endl;



    
    

    
    
    
  return 0;
}
