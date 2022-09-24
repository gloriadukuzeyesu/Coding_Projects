//
//  main.cpp
//  FunctionPractice
//
//  Created by Gloria Dukuzeyesu on 8/26/22.
//

#include <iostream>
#include<string>
#include<cmath>
#include <ctime>
#include <cassert>

using namespace std;

//function to create the hypotenuse
float hy(float length, float width){
    float result = sqrt(length*length + width* width);
    return result;
}
//function to formula of x and y part 2
void formula(double speed, double angle){
    float Xresult = speed*cos(angle);
    float Yresult = speed*sin(angle);
    cout<<"The X value: "<<Xresult<<" and "<<"The Y value: "<<Yresult<<endl;
}
//function that that takes in a string parameter and returns whether or not the string starts with a capital letter.
void isCapitalized(string word){
    bool letter = isupper(word[0]);
    if(letter){
        cout << "First letter is Capital"<<endl;
    }
    else{
        cout<< "Fist letter is NOT Capital"<<endl;
    }
}
//function takes in a Boolean parameter and returns the string
string boolToString( bool checkIfTrueOrFalse){
    bool TrueOrFalse =true;
    if (TrueOrFalse == true){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
//write a function called isPrime that takes an integer and returns whether or not it's a prime number
//if x is not equal to 2

bool isPrime(int x){
    if (x != 2){
        // 1 and 0 are not prime numbers
        if (x < 2 || x % 2 == 0) {
            return false;
        }
        //starting from 3<, every number
        for(int i=3; (i*i)<=x; i+=2){
            if(x % i == 0 ){
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
//Part 1
    //a
    //define variables
    float length;
    float width;
    //Ask the user to enter the length
    cout<<"Enter the length Triangle"<<endl;
    cin>>length;
    //ask the user to enter the width
    cout<<"Enter the width of the triangle: "<<endl;
    cin>>width;
    float resultMain = sqrt(length*length + width* width);
    cout<< "Result in Main " << resultMain;
    float calculatedResult= hy(length, width);
    cout<<calculatedResult<<endl;
    
    //b
    //define function
    double speed;
    double angle;
    //prompt the user to enter the speed
    cout<<"Enter the speed: "<<endl;
    cin>>speed;
    //prompt the user to enter the angle
    cout<<"Enter the angle in radians: "<<endl;
    cin>>angle;
    //call the function
   formula(speed,angle);

    //c
    std::time_t result = std::time(nullptr);
        std::cout << std::asctime(std::localtime(&result))
                  << result << " seconds since the Epoch\n";
//Part2
    //Why would it be difficult to turn the speed/velocity task above into a function?
    // because the fx() always returns one value. and the question ask to print two values
    // the imperfect way is use a void function that returns nothing and reuse it in the main()
    
    string EnteredWord;
    cout<<"Enter the word: "<<endl;
    cin>>EnteredWord;
    isCapitalized(EnteredWord);
    
//    bool itRaining=true;
//    cout<<boolToString(itRaining)<<endl;
//
    //check prime number
    int number;
    cout<<"Enter a number to check if it's prime or not: "<<endl;
    cin>>number;
    isPrime(number);
    
    if (isPrime(number)== true) {
        cout<< number<<" is prime"<<endl;
    }
    else{
        cout<< number<<" is NOT prime"<<endl;
    }
}


