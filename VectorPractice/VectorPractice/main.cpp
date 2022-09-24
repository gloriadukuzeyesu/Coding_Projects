//
//  main.cpp
//  VectorPractice
//
//  Created by Gloria Dukuzeyesu on 8/29/22.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;


 
int main(int argc, const char * argv[]) {
    vector<int> vec;
    int Numb=12;
    for (int i=0; i<6; i++) {
        vec.push_back(Numb+i);
    }
    
    for(int e : vec) {
        cout << e << " ";
    }
//    cout<<vec<<endl;
    return 0;
}
