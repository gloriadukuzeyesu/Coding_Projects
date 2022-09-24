//
//  main.cpp
//  DateFormats
//
//  Created by Gloria Dukuzeyesu on 8/25/22.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
    //declaration of variables
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
    year = UserinputDate.substr(6,4);
    
    //convert strings to integers
    int newMonth = stoi(month);
    int newDay = stoi(day);
    int newYear = stoi(year);
    
    //conver month into string. To get the month in English format such as January
    string convertedMonth = std::to_string(newMonth);
    
    //use if statement to set the range months and days that a user can select from. If a user select outside of the range. they will get an invalid date message
    if (convertedMonth == "1" && (1<=newDay && newDay<=31)){
        convertedMonth = "January";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "2" && (1<=newDay && newDay<30)){
        convertedMonth = "February";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if(convertedMonth == "3"&& (1<=newDay && newDay <=31)){
        convertedMonth = "March";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "4" && (1<=newDay && newDay <=30)){
        convertedMonth = "April";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "5"&& (1<=newDay && newDay <=31)){
        convertedMonth = "May";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "6" && (1<=newDay && newDay <=30)){
        convertedMonth = "June";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if(convertedMonth == "7"&& (1<=newDay && newDay <=31)){
        convertedMonth = "July";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "8" && (1<=newDay && newDay <=31)){
        convertedMonth = "August";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "9" && (1<=newDay && newDay <=30) ){
        convertedMonth = "September";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if(convertedMonth == "10" && (1<=newDay && newDay <=31)){
        convertedMonth = "October";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "11" && (1<=newDay && newDay <=30)){
        convertedMonth = "November";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else if (convertedMonth == "12" && (1<=newDay && newDay <=31)){
        convertedMonth = "December";
        cout<<convertedMonth<<" "<<newDay<<","<<newYear<<endl;
    }else{
        cout<<"Invalid date"<<endl;
    }

 return 0;
}
