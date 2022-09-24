
#include <iostream>
#include "PoliStructs.hpp"
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    Politician p1,p2,p3;
    p1.name = "Joe Biden";
    p1.partyAffiliation = "Javacan";
    p2.name = "Gloria";
    p2.partyAffiliation = "Cpluser";
    p3.name ="Nicolas";
    p3.partyAffiliation= "Cpluser";
    
    vector<Politician> politicians;
    politicians.push_back(p1);
    politicians.push_back(p2);
    politicians.push_back(p3);
    
    vector<Politician> output = Javacans(politicians);
    for(Politician p: output){
        cout<< p.name << ", "<<endl;
    }
    vector<Politician> List_Of_Cplusers = federalCplusers(politicians);
    for(Politician pol: List_Of_Cplusers){
        cout<< pol.name<<endl;
    }
    return 0;
}
