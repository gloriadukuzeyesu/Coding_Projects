//virtual functions
// pure functions


#include <iostream>
using namespace std;

class Instrument {
private:
    //member variables
    
public:
    virtual void MakeSound(){
        cout << "Instrument is playing" << endl;
    }
};

//derived class
class Guitar: public Instrument {
public:
    void MakeSound(){
        cout << "Guitar is playing" << endl;
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
    
    return 0;
}
