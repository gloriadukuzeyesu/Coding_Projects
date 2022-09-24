//
//  main.cpp
//  GiveChange
//
//  Created by Gloria Dukuzeyesu on 8/23/22.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int ItemPrice;
    std::cout<<"Enter the item price in cents \n";
    std::cin>> ItemPrice;
    
    int AmountPaid;
    std::cout<<"Enter the amount paid in cents \n";
    std::cin>>AmountPaid;
    
    //report the total amount of change to return after vending an item
    int Change= AmountPaid - ItemPrice;
    std::cout<<"Change= "<< Change<<" Cents";
    
    int Quarters= Change/25;
    Change= Change % 25;
    
    int Dime = Change/10;
    Change= Change % 10;
    
    int Nickels= Change/5;
    int Pennies= Change % 5;
    
    
    
    std::cout<<"\n Quarters: " <<Quarters<<"\n Dime: "<<Dime<<"\n Nickels"<<Nickels<<"\n Pennies"<<Pennies<<std::endl;
    return 0;
}
