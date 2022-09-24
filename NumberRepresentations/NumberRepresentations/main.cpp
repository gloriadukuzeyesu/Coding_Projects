
#include <iostream>
#include <cstdint>
#include <assert.h>
#include <iomanip>
#include <cmath>
#include <fstream>


using namespace std;

void loadInFile(ifstream& fin){
    ifstream fins;
    fins.open("UTF-8-demo.txt", ios_base::in);

    if (fins.is_open()) {
        char c;
        while (fins >> c) {
            cout << c << endl;
        }
    }
    
    else{
        cout <<" file failed to open" << endl;
    }
    
}

//bool approxEquals( double a, double b, double tolerance ){
//    abs(a) == abs(b)
//
//
//}


int main(int argc, const char * argv[]) {
    
    char myChar = 'B';
    int myNum = 5;
    int array[] = { 7, 2, -56, 32, 1, 7, -2, 7 };
    uint16_t Uint16_test;
    uint8_t uint8_t_test;
    uint64_t uint64_t_test;
    
    cout << sizeof(myChar) << endl;
    cout << sizeof(myNum) << endl;
    cout << sizeof(array) << endl; // size of this array in bytes is 32bytes
    cout << sizeof(Uint16_test) << endl; // size is 2 byte unsigned integer which confirms what has been published
    cout << sizeof(uint8_t_test) << endl; //  size of 1 byte unsigned integer
    cout << sizeof(uint64_t_test) << endl; // size of 8 byte unsigned integer
    
    
    uint16_t min = 0xFF;
    uint16_t max = 0x1E;
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    //by adding 1, the value increased by 1 value
    cout << "min+1: " << min + 1 << endl;
    cout << "max+1: " << max + 1 << endl;
    
    
    
    uint8_t mini = 0xFF;
    uint8_t maxi = 0x1E;
    cout << "mini: " << +mini << endl;
    cout << "maxi: " << +maxi << endl;
    //by adding 1, the value increased by 1 value
    cout << "mini+ 1: " << +mini + 1 << endl;
    cout << "maxi+ 1: " << +maxi + 1 << endl;
    
    uint64_t minim = 0xFF;
    uint64_t maxim = 0x1E;
    cout << "minim: " << minim << endl;
    cout << "maxim: " << maxim << endl;
    //by adding 1, the value increased by 1 value
    cout << "minim+ 1: " << minim + 1 << endl;
    cout << "maxim+ 1: " << maxim + 1 << endl;
    
    //signed int
    short s = 0xFF;
    int i = 0x1E;
    long l = 0x11;
    cout << "s : " << s << endl;
    cout << "i : " << i << endl;
    cout << "l : " << l <<  endl;
    //by adding 1, the value increased by 1 value
    cout << "s+1 : " << s + 1 << endl;
    cout << "i+1 : " << i + 1 << endl;
    cout << "l+1 : " << l + 1 <<  endl;
    
    //part2 floating point
    double num = .1 + .2;
    float numb = .1 + .2;
//    assert(numb == .3); // gives an error
    
    cout << "Double: "<< num << endl;
    cout << "Float: "<< numb << endl;

    std::cout << std::setprecision(18);
    
    ifstream fins("UTF-8-demo.txt");
    loadInFile(fins);
    
    
//    ifstream fins;
//    fins.open("UTF-8-demo.txt", ios_base::in);
//
//    if (fins.is_open()) {
//        char c;
//        while (fins >> c) {
//            cout << c << endl;
//        }
//    }
//    else{
//        cout <<" file failed to open" << endl;
//    }
//
//
    


    
    

    
    
    
    
    

    
    

    
    

    

    

    return 0;
}
