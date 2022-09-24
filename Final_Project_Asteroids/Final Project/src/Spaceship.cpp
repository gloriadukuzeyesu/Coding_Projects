#include "Spaceship.hpp"

// Private Functions

void Spaceship::InitializeTexture(){
    //Load a texture from file
    if(!texture.loadFromFile("./spaceship1.png")){
        std::cout<<"Unable to access the file"<<"\n" ; 
    }
}

void Spaceship::InitializeSprite(){
    sprite.setTexture(texture) ; // Setting the texture to sprite
    sprite.scale(0.5f, 0.5f) ;     // Resizing the sprite
}

void Spaceship::InitializeVariables(){
    MovementSpeed = 12.f ;
    ShootCoolDownMax = 10.f ;
    ShootCoolDown = ShootCoolDownMax ;
    
    hpMax = 10 ;
    hp = hpMax;
}

// Constructor and Destructor

Spaceship::Spaceship() {
    
    InitializeVariables();
    
    InitializeTexture() ;
    InitializeSprite() ;

    sprite.setPosition(700, 1200) ;

}


Spaceship::~Spaceship() {
    
    
}


// Public Functions

const sf::Vector2f& Spaceship::getPos() const {
    
    return sprite.getPosition() ;

}


const sf::FloatRect Spaceship::getBounds() const {
    
    return sprite.getGlobalBounds() ;
}


const int& Spaceship::getHP() const {
    
    return hp;
}


const int& Spaceship::getHPmax() const {
    
    return hpMax ;
    
}

void Spaceship::SetHp(const int hp)
{
    
    this->hp = hp ;
    
}

void Spaceship::Hplost(const int value)
{
    // eachtime spaceship losse, value will be taken from hp
    this->hp -= value ;
    if(this->hp < 0)
    {
        this->hp = 0 ;
    }
    
}

void Spaceship::setPosition(const sf::Vector2f pos){
    
    sprite.setPosition(pos) ;
    
}


void Spaceship::SetPosition(const float x, const float y){
    
    sprite.setPosition(x, y) ;
    
}


void Spaceship::move(const float x_dir, const float y_dir){
    
    sprite.move((MovementSpeed * x_dir) , (MovementSpeed * y_dir)) ;
    
}

bool Spaceship::canShoot() {
    
    if (ShootCoolDown >= ShootCoolDownMax) {
        
        ShootCoolDown = 0.f ;
        return true ;
    }
    return false;
    
}


void Spaceship::updateShoot(){
    
    if(ShootCoolDown < ShootCoolDownMax){
        ShootCoolDown += 0.5f;
    }
}


void Spaceship::update() {
    
    updateShoot() ;
}

void Spaceship::render(sf::RenderTarget& target) {
    
    target.draw(sprite) ;
}
