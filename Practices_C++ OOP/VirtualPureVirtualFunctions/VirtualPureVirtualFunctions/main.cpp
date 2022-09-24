//virtual functions
// pure functions
// abstract class is a class whihc has at least one virtual function


#include <iostream>
using namespace std;

class Instrument {

public:
    virtual void MakeSound() = 0;  // pure virtual function
    // this means that every function that will inherit from base class ( class instrumetn)
    // will have to provide its own derived function makesound()
    //
};
//derived class
class Guitar: public Instrument {
public:
    void MakeSound(){
        cout << "Guitar is playing" << endl;
    }
};

class Piano : public Instrument {
public:
    void MakeSound(){
        cout << "Piano is playing" << endl;
    }
};

int main(int argc, const char * argv[]) {
    /*
     when the method shared both in base class and derived class is invoked using
     pointer. The most derived function of that method should be executed.
     You must use virtual keyword in the base function
     */
    Instrument* I1 = new Guitar();
    I1->MakeSound();
    
    //pure virtual function implementation
    Instrument* I2 = new Piano();
    I2->MakeSound();
  
    cout <<"--------------------implementation of polymorphism-------------------- " << endl;
    // make an array of Instrument class pointer
    Instrument* Instruments [2] = {I1, I2};
    for(int i= 0; i< 2; i++){
        Instruments[i] -> MakeSound();
    }
    return 0;
}
