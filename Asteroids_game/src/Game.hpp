//
//  Game.hpp
//  testSFML
//
//  Created by Lakshay Santosh Kucheriya on 9/21/22.
//

# pragma once
#include <stdio.h>
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include <map>
#include <string>
#include <sstream>

class Game{ 
  
private:
    /*------------Window--------------------*/
    sf::RenderWindow* window  ; // Using it as a pointer because it will be easier to create and destroy
    
    /*------------Bullet--------------------*/
    //an array of textures,for each string, there is going to be a texture.
    // a pointer of texture to make sure the textures has the right ones and no copies 
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets; //create a vector of bullets. a pointer for optimization
    
    /*------------GUI--------------------*/
    sf::Font font;
    sf::Text TextForPoint;
    
    sf::Text gameOverText ;
    
    /*-----------Background-------------------------*/
    
    
    sf::Texture BackgroundTexture ;
    sf::Sprite Background ;
    
    
    /*-----------Logistics-------------------------*/
    
    unsigned points ;
    
    
    /*------------Asteroids--------------------*/
    float Spawntimer;
    float SpawntimerMax;
    std::vector<Asteroid*> Asteroids; // vector of many asteroids
    
    
    /*------------spaceship--------------------*/
    Spaceship* spaceship ;
    
    sf::RectangleShape hpBar ;
    sf::RectangleShape hpBarchange ;
  

    
    // Private Functions
    void InitializeWindow() ;
    void initalizationTexture(); // load all player texture
    void InitializeGUI();
    void InitializeBackground() ;
    void InitializeLogistics() ;
    
    void InitializeSpaceship();
    void InitializationAsteroid();
    
public:
    Game() ;
    ~Game() ;
    
    void execute() ; // to run the game
    
    void updatePollEvents();
    
    void updateInput(); // update all the user input
    void updateGUI();
    void updateWorld();
    void updatePlayerCollision();
    void updateBullets();
    void updateAstroids();
    void updateCollision() ;
    void update() ; // Game updates in each frame
    
    void renderGUI();
    void renderWorld() ;
    void render() ; // Draws the updated positions
    
};

//// create the window
//    sf::RenderWindow window(sf::VideoMode(1000,800), "Asteroids");
//    window.setFramerateLimit(60);
//    //load in an image
//    sf::Texture textureBackground;
//    sf::Texture textureSpaceship;
//    textureBackground.loadFromFile("/Users/gloriadukuzeyesu/MSD/CS6010-Final-Project/Final Project/images/background.jpg");
//    textureSpaceship.loadFromFile("/Users/gloriadukuzeyesu/MSD/CS6010-Final-Project/Final Project/images/spaceship.png");
//
//
//    //create the sprite
//    sf::Sprite mybackgroundSprite;
//    sf::Sprite spaceshipSprite;
//
//    mybackgroundSprite.setTexture(textureBackground);
//    spaceshipSprite.setTexture(textureSpaceship);
//    spaceshipSprite.scale(0.5f,0.5f);
//    spaceshipSprite.setPosition(50.0, 650.0); // set pos
////    spaceshipSprite.move(0.0, 0.0);
//
//
//
//
//    // run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//                window.close();
//        }
//
//    window.clear();
//    window.draw(mybackgroundSprite);
//    window.draw(spaceshipSprite);
//    window.display();
//}
