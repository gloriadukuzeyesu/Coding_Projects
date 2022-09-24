
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Bullet {
private:
    sf:: Sprite shape;
    sf::Vector2f direction;
    float MovementSpeed; // the speed
    
public:
    //default constructor
    Bullet();
    
    //constructor . has to have a position ( x, y), th speed, and the texture
    Bullet(sf::Texture* texture , float pos_x , float pos_y , float X_direction , float Y_direction , float _Speed);
    
    //deconstrucor
    ~Bullet();
    
    //access the position coordinate of the sprite through floatReact getbounds.
    const sf:: FloatRect getBounds() const;

    //methods
    void update();
    //void draw(sf::RenderWindow& window) const;
    void render(sf::RenderTarget* target);    
};









