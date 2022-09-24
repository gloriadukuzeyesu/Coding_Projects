#pragma once
#include <vector>


//list of functions and struct
struct Politician{
    std::string name;
    std::string partyAffiliation;
    bool IsAStatePolitican;
    bool IsAFederalPolitican;
};

std::vector<Politician> Javacans(std::vector<Politician> politicians);
std::vector<Politician> federalCplusers(std::vector<Politician> politicians);


