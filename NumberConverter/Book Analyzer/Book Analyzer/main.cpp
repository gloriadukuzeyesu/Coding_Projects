

#include <iostream>
#include <fstream>
#include <cstdlib> // For exit() function
#include <string>
#include <sstream>
#include <vector>
#include "BookAnalyzer.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //declare variables
    string filename;
    string keyWord;
    ifstream fin; // file input
    
    cout << "Available files:\n" <<" MotherBunny.txt \n";
    cout << "Enter file from the above list: " << endl;
    cin >> filename;
    
    cout << "Enter keyword: " << endl;
    cin>> keyWord;
    
    fin.open(filename,ios_base::in);
    if (fin.fail()){
        cout << " failed to open" <<endl;
        exit(1);
    }
    else{
        vector<string> VectorOfStrings;
        string word;
        while ( fin >> word ) {
            VectorOfStrings.push_back(word);
        }
        fin.close();
       
        cout << "Title:" << find_Title(VectorOfStrings) << endl;
        cout << "Author:" << findAuthor(VectorOfStrings) << endl;
        cout << "The Shortest Word is: " << getShortWord(VectorOfStrings)<< " and the longet word is: "<< getLongestWord(VectorOfStrings)<<endl;
        cout << "Number of words: " << numWord(VectorOfStrings) << endl;
        cout << "number of character: "<< getNumOfChars(VectorOfStrings) << endl;
        
        searchForKeyWord(VectorOfStrings, keyWord);


    }
    
              
    return 0;
}
