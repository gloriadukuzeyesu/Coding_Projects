/* ----NOTES--
 1. abstraction means showing and displaying important information while hidding the
    unimportant and complex information the things that are absract are  usually changed but nothing is changed for the end user
 2. abstract class is a class whihc has at least one pure virtual function  */

#include <iostream>
using namespace std;

/* abstract class */
class SmartPhone{
public:
    virtual void TakeAselfie() = 0; //abstract class because of having at least
    //one virtual functions. Also it means we can't create instances of this abstract class
    // we can create pointers of abstract class
    virtual void MakeACall() = 0;
};

// derived class
class Android : public SmartPhone {
public:
    void TakeAselfie() {
        cout << "Android takes a selfie" << endl;
    }
    void MakeACall() {
        cout << "Android makes a call" << endl;
    }
};

//derived class
class Iphone : public SmartPhone {
public:
    void TakeAselfie() {
        cout << "Iphone is taking a selfie" << endl;
    }
    void MakeACall() {
        cout << "Iphone makes a call" << endl;
    }
};


int main(int argc, const char * argv[]) {
    
    SmartPhone* s1 = new Android();
    s1-> TakeAselfie(); // used -> when invocking a method with a pointer
    s1->MakeACall();
    
    SmartPhone* iphone2 = new Iphone();
    iphone2 -> TakeAselfie();
    iphone2 -> MakeACall();
    /*
     you don't need to know how the implementatio of functions whihc is
     you make a class. and everyone who wants to use your class doen't need to
     know the complexity of how certain functions work. instead they know the
     interface of all functions and how to used them in simple ways
     */

    return 0;
}
