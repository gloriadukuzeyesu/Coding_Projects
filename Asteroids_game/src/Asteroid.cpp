
#include "Asteroid.hpp"
#include "SFML/Graphics.hpp"


void Asteroid::initialVariable(){
    
    sf:: CircleShape shape;
    speed = 4.f ;
    hp = 10;
    hpmax = 15;
    damage = 1;
    points = 5;
}



void Asteroid::initialShape()
{
    shape.setRadius(rand() % 20 + 20); // randomly get a radius 
    shape.setPointCount(rand() % 20 + 3); // selects the egdes or vertex of the shape
//    shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
//    shape.setFillColor(sf::Color:: Red);
    shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
    // RGB colours and transperency so each color goes from 0-255
}



Asteroid::Asteroid()
{
    
}

//constructor

Asteroid::Asteroid(float x_pos, float y_pos){
    

    initialShape();
    initialVariable();
    shape.setPosition(x_pos, y_pos);  // should check for edge cases where bullet can't hit
}

//de-connstructor
Asteroid::~Asteroid(){
    
}


const sf::FloatRect Asteroid::getBounds() const{  // No reference as FloatRect already returns a reference
    
    return shape.getGlobalBounds();
    
}


const int& Asteroid::getPoints() const{
    
    return points ;
}


const int& Asteroid::getDamage() const
{
    return damage ;
}


//reset
void Asteroid::update(){

    shape.move(0.f , speed) ;
}


//  render the enemy
void Asteroid::render(sf::RenderTarget* target){
    target->draw(this->shape);
}

