

#include <vector>
#include <string>
#include "PoliStructs.hpp"
using namespace std;

vector<Politician> Javacans(vector<Politician> politicians)
{
    vector<Politician> javacans;// holds all the javacans
    for(Politician politician: politicians){
        if(politician.partyAffiliation == "Javacan"){
            javacans.push_back( politician);
        }
    }
    return javacans;
}
vector<Politician> federalCplusers(vector<Politician> politicians)
{
    vector<Politician> listOfCplusers; // a list of federalCplusers
    for(Politician candidate: politicians)
    {
        if (candidate.partyAffiliation == "Cpluser") {
            listOfCplusers.push_back(candidate);
        }
    }
    return listOfCplusers;
}





