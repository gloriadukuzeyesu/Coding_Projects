#pragma once

#include <SFML/Graphics.hpp>

/* enemy class
 1. contains the cirlce shape for the enemy, randomly create the shape of the enemy based on the sf::CircleShape classs
 2. the damage caused by enemy,
 3. the points gained by player
 */

class Asteroid {
private:
    // member variables
    sf::CircleShape shape;
    float speed ;
    int hp;
    int hpmax;
    int damage;
    int points;
        
    void initialShape();
    void initialVariable();
    
public:
    Asteroid();
    Asteroid(float x_direction, float y_directioin);
    ~Asteroid();
    
    // Accessors
    const sf::FloatRect getBounds() const ;
    const int& getPoints() const ;
    const int& getDamage() const ;
    
    
    void update();
    void render(sf::RenderTarget* target);
};












