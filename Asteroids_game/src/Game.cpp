//
//  Game.cpp
//  testSFML
//
//  Created by Lakshay Santosh Kucheriya on 9/21/22.
//

#include "Game.hpp"
#include "Bullet.hpp"
#include "Asteroid.hpp"
#include "Spaceship.hpp"


// Private Functions
void Game::InitializeWindow() {
    
    window = new sf::RenderWindow(sf::VideoMode(1600,1200), "Game") ;
    window->setFramerateLimit(60) ; // It is important to limit Frame Rate for same performances in each machine
    window->setVerticalSyncEnabled(false);
    // Never use both setVerticalSyncEnabled and setFramerateLimit at the same time! They would badly mix and make things worse. 
}

//load all the player game 
void Game::initalizationTexture(){
    // at the position string Bullets, create a new texture and load in a file into the textures map
    textures["Bullets"] = new sf::Texture();
    textures["Bullets"]->loadFromFile("./laser2.png");
}
//Users/gloriadukuzeyesu/MSD/CS6010-Final-Project/Final Project/images/laser2.png

void Game::InitializeGUI(){
    // loading the font
    if(!font.loadFromFile("./Glorine.otf"))
        std::cout << "FAILED TO LOAD IN FONT!! " << std::endl;
    
    // Text point initialization
    TextForPoint.setFont(font);
    TextForPoint.setCharacterSize(50);
    TextForPoint.setFillColor(sf::Color::White);
    TextForPoint.setStyle(sf::Text::Bold);
    TextForPoint.setString("Hello Gamer");

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(200);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setString(" Game Over !!!");
    //set the position of game over in the center of the screen and only display it only when the game is over
    gameOverText.setPosition(
                             this->window->getSize().x/2.f - gameOverText.getGlobalBounds().width/2.f,
                             this->window->getSize().y/2.f - gameOverText.getGlobalBounds().height/2.f) ;
    
    /*-------PLAYER GUI----------*/
    
    hpBar.setSize(sf::Vector2f(300.f, 25.f)) ;
    hpBar.setFillColor(sf::Color::Red) ;
    hpBar.setPosition(20.f, 80.f) ;
    
    hpBarchange = hpBar ;
    hpBarchange.setFillColor(sf::Color(25, 25, 25, 200)) ;
    
    
}

void Game::InitializeBackground(){
    
    if(!BackgroundTexture.loadFromFile("./Background2.jpeg")){
        
        std::cout<<"ERROR LOADING FILE" ;
    }
    
    Background.setTexture(BackgroundTexture) ;
}


void Game::InitializeLogistics(){
    
    points = 0 ;
    
}

void Game::InitializeSpaceship() {
    spaceship = new Spaceship() ;
}

void Game::InitializationAsteroid(){
    SpawntimerMax  = 50.f;
    Spawntimer = SpawntimerMax;
}

//initilialize the every element of the game
Game::Game() {
    InitializeWindow() ;
    initalizationTexture() ;
    InitializeGUI() ;
    InitializeBackground() ;
    InitializeLogistics() ;
    
    InitializeSpaceship() ;
    InitializationAsteroid() ;
}

// Constructor and Destructor
Game::~Game() {
    
    delete window ;
    delete spaceship ;
    
    // delete the textures after use. by using a for each loop and delete second(the value in map)
    for (auto &i : this->textures){
            delete i.second;
        }
    
    //delete all the Bullets
    for(auto*i : this->bullets){
        delete i;
    }
    
    
    //delete all the asteroids to free the memory
    for(auto*i : this->Asteroids){
        delete i;
    }
}





// Public Functions

void Game::execute() {
    
    while(window->isOpen())
    {
        updatePollEvents(); // update basic needs we need to update for the game
        
        if(spaceship->getHP() > 0)  // when the health bar is less than 0, update the game
        {
            update() ; // update game
        }
        render() ;
    }
    
}

void Game::updatePollEvents(){
    sf::Event e ;
    
    while(window->pollEvent(e)){
        if(e.Event::type == sf::Event::Closed){
            window->close() ;
            // For closing the window using escape key on the keyboard we can write an if statement using Keypressed()
        }
    }
}


void Game::updateInput(){
    // keyboard control for the player

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        spaceship->move(-1.f , 0.f) ;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        spaceship->move(1.f , 0.f) ;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        spaceship->move(0.f , -1.f) ;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        spaceship->move(0.f , 1.f) ;
    }
    
    // create the bullets at the position of the player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && spaceship->canShoot())
    {
        bullets.push_back
            (new Bullet(
             textures["Bullets"],
             this->spaceship->getPos().x + (this->spaceship->getBounds().width/2.f) - 12 ,
             this->spaceship->getPos().y,
             0.f, -1.f, 5.f));
    }
    
}

void Game::updateGUI(){
    
    std::stringstream ss;
    
    ss<<" Score : " <<points ;
    
    TextForPoint.setString(ss.str()) ;
    
    //Update Player GUI
    float hpPercent = static_cast<float>(spaceship->getHP()) / spaceship->getHPmax() ;
    hpBar.setSize(sf::Vector2f(300.f * hpPercent , hpBar.getSize().y)) ;

    
}

void Game::updateWorld(){
    
    
}

//setting bounds for the spaceship so that it won't go beyond the screeen size
void Game::updatePlayerCollision(){
    
    //Checking for left collision
    
    if(spaceship->getBounds().left <0.f){
        
        spaceship->SetPosition(0.f, spaceship->getBounds().top) ;
    }
    
    // Checking for the right collision
    
    else if(spaceship->getBounds().left + spaceship->getBounds().width > window->getSize().x){
        
        spaceship->SetPosition(window->getSize().x - spaceship->getBounds().width, spaceship->getBounds().top) ;
    }
    
    // Checking for top collision
    if(spaceship->getBounds().top < 0.f){
        
        spaceship->SetPosition(spaceship->getBounds().left, 0.f) ;
    }
    
    else if(spaceship->getBounds().top + spaceship->getBounds().height > window->getSize().y){
        
        spaceship->SetPosition(spaceship->getBounds().left , window->getSize().y - spaceship->getBounds().height) ;
    }
}



void Game::updateBullets (){
   
    unsigned counter = 0 ;
    
    for(auto *bullet: bullets){
        bullet -> update();
        
        // If bullet goes out of the screen
        //Bullet culling (top of screen)
        if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
        {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
        }
        counter++;
    }
}

void Game::updateAstroids(){
    Spawntimer += 0.8f;
    // if the spawtimer is greater than or equal to spawntimer max, then we will restart
    if (Spawntimer >= SpawntimerMax) {
        Asteroids.push_back(new Asteroid(rand() % 1400 + 100.f, -100.f)); // steroid have to stay within the window.
        // the asteroid will be spawn within this area
        Spawntimer = 0.f;
    }
    //after spawing the asteroid update all other asteroids
   
    
    unsigned counter = 0 ;
    
    for(auto *Asteroid: Asteroids){
        Asteroid -> update();
        
        // If Asteroid passed the top of the screen, delete it

        if (Asteroid->getBounds().top > this->window->getSize().y)
        {
            //Delete bullet
            delete this->Asteroids.at(counter);
            this->Asteroids.erase(this->Asteroids.begin() + counter);
        }
        else if (Asteroid->getBounds().intersects(spaceship->getBounds())){
            
            spaceship->Hplost(Asteroids.at(counter)->getDamage());
//            spaceship-> Hplost(0);
            delete this->Asteroids.at(counter);
            this->Asteroids.erase(this->Asteroids.begin() + counter);
            
        }
        
        counter++;
    }
    
}


void Game::updateCollision(){
  
    for(int i = 0 ; i< Asteroids.size() ; i++){
        
        bool AsteroidRemoved = false;
        Asteroids[i]->update() ; //after spawing the asteroid update all other asteroids
        
        //remove the bullet and the asteroids when they collide each other
        for (size_t k=0; k < bullets.size() && !AsteroidRemoved ; k++) {
            if (bullets[k] -> getBounds().intersects(Asteroids[i]-> getBounds())) {
                
                delete bullets[k] ;
                bullets.erase(bullets.begin() + k); //erase the bullet
                
                points += Asteroids[i]->getPoints() ;
                
                delete Asteroids[i] ;
                Asteroids.erase(Asteroids.begin() + i); //erase the asteroids
                AsteroidRemoved = true;
            }
            
        }
        // if the asteroids have not been removed, they will be removed  at the end of the screen
        if (!AsteroidRemoved) {
            //remove the asterois when they pass over the bottom of the the window
            if(Asteroids[i]->getBounds().top > this->window->getSize().y){
                std::cout<< Asteroids.size() << std::endl;
                Asteroids.erase(this->Asteroids.begin() + i); // erase the asteroids
                AsteroidRemoved = true;
            }
            
        }

    }
    
}



//update all elements of the game in the one function. 
void Game::update() {
    updateInput();
    spaceship->update() ;
    updatePlayerCollision();
    updateBullets();
    //updatePollEvents();
    updateAstroids();
    updateCollision();
    updateGUI();
    updateWorld() ;
}

//render the GUI
void Game::renderGUI(){
    window->draw(TextForPoint);
    window->draw(this->hpBarchange) ;
    window->draw(this->hpBar) ;
}

void Game::renderWorld(){
    
    window->draw(Background) ;
}

void Game::render() {
    
    window->clear() ;
    
    // Draw Background
    
    renderWorld() ;
    
    // Draw on th screen
    spaceship->render(*window) ;
    
    for(auto *bullet: bullets)
    {
        bullet ->render(window);
    }
    
    //draw the asteroid on the screen
    for(auto *asteroid: Asteroids)
    {
        asteroid -> render(window);
    }
    
    renderGUI() ;
    
    /*--------------------Game Over Screen--------------------*/
    // render only when the the spaceship's life is 0
    if(spaceship->getHP() <= 0)
    {
        window->draw(this->gameOverText) ;
    }
    
   // this->window->draw(TextForPoint);
    
    window->display() ;
}


