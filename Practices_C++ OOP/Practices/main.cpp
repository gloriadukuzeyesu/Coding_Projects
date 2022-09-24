/*
 Exercises C++ Object-Oriented Programming
 Topics covered are:
 1. Classes and objects
 2. constructors and class methods
 3. Encapsulation
 4. Inheritance
 5. Polymorphisam: describes the ability of an object to have multiple forms. Two or more objects that inherit from the same   base class and have same methods with different implementation
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;


class YoutubeChannel{
    
private:
    string Name;
    int Subscriberscount;
    list<string> PublixhedVideoTitle;

protected: // this protected member variable can be accessed by both the base and derived classes
    string OwnerName;
    int counterQuality;
public:
    //constructor
    YoutubeChannel (string Name_, string OwnerName_){
        this->Name = Name_;
        this->OwnerName = OwnerName_;
        this->Subscriberscount = 0;
    }
    //methods
    void getInfor(){
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "Subscriberscount: " << Subscriberscount << endl;
        cout << "List of Videos: " << endl;
        for(string videoTitle: PublixhedVideoTitle){
            cout<< videoTitle << endl;
        }
    }
    void subsribe(){
        Subscriberscount++;
    }
    void unsubsribe(){
        if (Subscriberscount > 0 )
        Subscriberscount--;
    }
    void published(string video){
        PublixhedVideoTitle.push_back(video);
    }
    string get(){ // get the name
        return Name;
    }
    string setter(string setName){
        Name = setName;
        return Name;
    }
    void checkanalystics(){
        if(counterQuality < 5){
            cout<< Name << " has poor quality content " << endl;
        }
        else{
            cout << Name << "  has great quality content" << endl;
        }
    }
};

//inheritance. Class CookingYoutubeChannel will inherit properties of YoutubeChannel
// base class is YoutubeChannel

class CookingYoutubeChannel: public YoutubeChannel{
public:
    //constructor for CookingYoutubeChannel
    CookingYoutubeChannel(string Name_, string OwnerName_) : YoutubeChannel(Name_, OwnerName_){
    }
    //methods for just CookingYoutubeChannel. Derived class
    void Practice(){
        cout<<OwnerName<<": Practicing cooking and trying out new recipes..." <<endl;
        counterQuality++;
    }
};

class SingersYoutubeChannel : public YoutubeChannel{
public:
    //constructor
    SingersYoutubeChannel(string Name_, string OwnerName_) : YoutubeChannel (Name_, OwnerName_){
    }
    //methods
    void Practice(){
        cout << OwnerName << " Practicing singing and dancing new moves. " << endl;
        counterQuality++;
    }
};


int main(int argc, const char * argv[]) {
    
    YoutubeChannel ytchannel("GloriaChannel", " Dukuzeyesu") ; // create an object using a constructor
    ytchannel.published("C++ for beginner");
    ytchannel.published("Java for beginner");
    ytchannel.subsribe();
    ytchannel.subsribe();
    ytchannel.unsubsribe();
    ytchannel.get();
    string NewName = "Aime";
    ytchannel.setter(NewName);
    cout <<ytchannel.get() << endl;
 
                     
    //invoke the method
    ytchannel.getInfor();
    
    cout <<"**********************************" << endl;
    
    YoutubeChannel MyVlog ("LindaCuisine","Claire Uwineza");
    //invoke the method
    MyVlog.published("Rice");
    MyVlog.published("beans");
    MyVlog.subsribe();
    MyVlog.getInfor();
    
    cout <<"**********************************" << endl;

    // creating an object from a derived class
    CookingYoutubeChannel FoodOnthePlate ("AlishaCooking", "Alisha Davison");
    FoodOnthePlate.published("ApplePie");
    FoodOnthePlate.published("Cake");
    FoodOnthePlate.subsribe();
    FoodOnthePlate.subsribe();
    FoodOnthePlate.getInfor();
    FoodOnthePlate.Practice();
    
    cout <<"**********************************" << endl;

    CookingYoutubeChannel FoodOnthePlate2 ("JamesCooking", "James Willson");
    FoodOnthePlate2.published("Cookies");
    FoodOnthePlate2.published("Salad");
    FoodOnthePlate2.subsribe();
    FoodOnthePlate2.subsribe();
    FoodOnthePlate2.getInfor();
    FoodOnthePlate2.Practice();
    
    cout <<"**********************************" << endl;

    FoodOnthePlate2.setter("mrsWillsonCooking");
//    cout << FoodOnthePlate2.get() <<endl;
    FoodOnthePlate2.getInfor();
    
    cout <<"************** Polymorphisam ********************" << endl;
    SingersYoutubeChannel AmySingingChannel ("AmySingingChannel", "Amy Harrison");
    AmySingingChannel.Practice();
    FoodOnthePlate.Practice();
    FoodOnthePlate.Practice();
    FoodOnthePlate.Practice();
    FoodOnthePlate.Practice();
    FoodOnthePlate.Practice();
    FoodOnthePlate.Practice();
    FoodOnthePlate.Practice();


    //use pointers
    // a pointer of base class can point to an object of a derived class.
    YoutubeChannel * youtube1 = &AmySingingChannel;
    YoutubeChannel * youtube2 = &FoodOnthePlate;
    
    //invoke the methods on this pointers
    youtube1->checkanalystics();
    youtube2->checkanalystics();

    
    return 0;
}
