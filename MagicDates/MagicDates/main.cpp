
#include <iostream>
#include<string>
using namespace std;

int main(int argc, const char * argv[]) {
    // Declaration of variables
    string UserinputDate;
    string month;
    string day;
    string year;
    //Prompt the user to enter the date
    cout<<"Enter the date in format mm/dd/yyyy: "<<endl;
    cin>>UserinputDate;
    //slice the input date into strings: string month, string day, and string year
    month = UserinputDate.substr(0,2);
    day = UserinputDate.substr(3,2);
    year = UserinputDate.substr(UserinputDate.length()-4,4);
    //convert strings to integers
    int newMonth = stoi(month);
    int newDay = stoi(day);
    //int newYear = stoi(year);
    //conver month into string. To get the month in English format such as January
    string convertedMonth = std::to_string(newMonth);
    //how to access the two last character of the year
    string lastTwoCharOfYear = UserinputDate.substr((UserinputDate.length()-2),2);
    //convert the last two char of the year into integers
    int newYearChar = stoi(lastTwoCharOfYear);
    
    //use if statement to set the range months and days that a user can select from. If a user select outside of the range.They will get an invalid date message
    if ((1<=newMonth && newMonth<=12) && (1<=newDay && newDay<=31) && ((newMonth * newDay) == newYearChar)){
        cout<<UserinputDate<<" is a Magic date"<<endl;
    }else if ((1<=newMonth && newMonth<=12) && (1<=newDay && newDay<=31)){
        cout<<UserinputDate<<" is Not a Magic Date"<<endl;
    }else{
        cout<<"Invalid Date"<<endl;
    }
        
    return 0;
}
