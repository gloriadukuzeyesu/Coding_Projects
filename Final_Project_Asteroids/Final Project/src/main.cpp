
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <time.h>

using namespace std;


int main(){
    srand(time(0)); // initialize the seed from the time. allows to generate random number
    Game game ;
    
    game.execute() ;

    return 0;
}
