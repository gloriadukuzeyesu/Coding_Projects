
#include <iostream>
#include <string>
#include <list>
using namespace std;

//members of structs are public by default

struct YouTubeChannel
{
    string _Name;
    int _SubscribersAccount;
    
    YouTubeChannel ( string Name, int SubscribersAccount) {
        _Name  = Name;
        _SubscribersAccount = SubscribersAccount;
    }
    
    bool operator==(const YouTubeChannel& channel) const
    {
        return this->_Name == channel._Name;
    }
    
    
};

//created as a global function with two parameter
ostream& operator<<(ostream& COUT, YouTubeChannel& Ytchannel)
{
    COUT << "Name: " << Ytchannel._Name << endl;
    COUT << "Subscribers: " << Ytchannel._SubscribersAccount << endl;
    return COUT;
};



struct Mycollection
{
    list <YouTubeChannel>myChannels;
    
    //methods because lhs is automatically provide
    void operator+= (YouTubeChannel& channel)
    {
        this -> myChannels.push_back(channel);
    }
    
    void operator-= (YouTubeChannel& channel)
    {
        this -> myChannels.remove(channel);
    }
};

//created as a global function with two parameter
ostream& operator<<(ostream& COUT, Mycollection& myCollection)
{
    for (YouTubeChannel ytchannel : myCollection.myChannels){
        COUT << ytchannel << endl;
    }
    return  COUT;
};



int main(int argc, const char * argv[])
{
    YouTubeChannel Yt1 ("AmyChannel", 1200);
    YouTubeChannel Yt2 ("MySecondChannel", 8000);
    YouTubeChannel Yt3 ("myThirdChannel", 200);

//    cout << Yt1 << Yt2;
    /* how to invoke operator overload such like the normal function. as it is a funcion itself */
//    operator << (cout, Yt3); // not usually used but it works
    
    
    Mycollection myCollection;
    myCollection += Yt1;
    myCollection += Yt2;
  
    cout << myCollection;

    return 0;
}
