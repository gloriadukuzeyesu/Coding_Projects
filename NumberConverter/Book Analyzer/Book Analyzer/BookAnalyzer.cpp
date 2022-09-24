
#include "BookAnalyzer.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;
std::vector<char> vectorOfChars;

//f() to find the title
string find_Title( vector<string> VectorOfWords){
    std::string title;
    int positionOfTitle = -1;
    int positionOfAuthor = -1;
    // -1 will be used in title is on the first position
    for (int i=0; i < VectorOfWords.size(); i++) {
        if (VectorOfWords[i] == "Title:") {
            positionOfTitle = i;
        } else if (VectorOfWords[i] == "Author:") {
            positionOfAuthor = i;
        }
    }
    for (int i = positionOfTitle + 1 ; i< positionOfAuthor; i++) {
        title = title +" "+ VectorOfWords[i];
    }
    return title;
}


//function to return the name of the author
string findAuthor( vector<string> VectorOfWords){
    std::string author;
    int positionOfAuthor = -1;
    int positinOfReleaseDate= -1;
    
    for(int i=0; i < VectorOfWords.size(); i++){
        if (VectorOfWords[i] == "Author:"){
            positionOfAuthor = i;
        }else if (VectorOfWords[i] == "Release"){
            positinOfReleaseDate = i;
        }
    }
    for (int i = positionOfAuthor+1; i < positinOfReleaseDate; i++) {
        author = author + " "+ VectorOfWords[i];
    }
    return author;
}


// function to return the The total number of words in the file
int numWord( vector<string> vect ){
    int counter =0;
    for (int i=0; i < vect.size(); i++){
        counter++;
    }
    return counter;
}

//function to return the shortest word
string getShortWord( vector<string> vect){
    string shortWord;
//    INT_MAX biggest number in integer
    long shortest = INT_MAX;
    for(string word: vect){
       if (word.length() < shortest){
            shortest = word.length();
            shortWord = word;
        }
    }
    return shortWord;
}

//function to return the longest word
string getLongestWord( vector<string> vect){
    string longestWord;
    int longest = 0;
    for(string word: vect){
        if (word.length() > longest){
            longest = (int) word.length();
            longestWord = word;
        }
    }
    
    return longestWord;
}

// function that counts number of char
int getNumOfChars(vector<string> VectorOfWords ){
    int count =0;
    for (int i=0; i<VectorOfWords.size(); i++) {
        // (int) helps to cast long to int
        count = (int)VectorOfWords[i].length() + count;
    }
    return count;
}



// function to search for the keyword
//find the location of the keyword. Index of the keyword
//calculate the occurance
//print the two words surrounding the keyword

void searchForKeyWord (vector<std::string> VectorOfWords, string word){
    int countAppearances=0;
    int countCharacters= 0;

    string wordOnTheLeftSide;
    string wordOnTheRightSide;
    
    
    vector<int> indexesOfKeywords;
    vector<string> context;
    vector<double> percentages;
    
    
    for (int i=0; i< VectorOfWords.size(); i++) {
        if (VectorOfWords[i] == word) {
            countAppearances ++;
            indexesOfKeywords.push_back(countCharacters);
            wordOnTheLeftSide = VectorOfWords[i-1];
            wordOnTheRightSide = VectorOfWords[i+1];
            context.push_back(wordOnTheLeftSide+ " " + VectorOfWords[i] + " " +wordOnTheLeftSide);
        }
        
        // count the lenght of all words and add them together
        countCharacters += VectorOfWords[i].length();
        
    }
    for (int i=0; i<indexesOfKeywords.size(); i++) {
        //put the percentage into vector.
        percentages.push_back((indexesOfKeywords[i] * 1.0 /countCharacters)*100);
        
    }
    cout << "The word " << word << " appears " << countAppearances << " times: " << endl;
    for (int i=0; i< countAppearances; i++) {
        
        cout<< "at " << percentages[i] << "%: " << context [i] << endl;
    }
}




    
    


    





