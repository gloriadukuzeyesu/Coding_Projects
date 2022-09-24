#include "Bullet.hpp"
//#include <SFML/Graphics.hpp>


Bullet::Bullet(){
    
}
//constructor has speed, x and y direction, x and y position, and texture
Bullet::Bullet(sf::Texture* texture , float pos_x , float pos_y , float X_direction , float Y_direction , float _Speed){
    
    shape.setTexture(*texture); // my shape
    shape.setPosition(pos_x, pos_y);
    direction.x = X_direction;
    direction.y = Y_direction;
    MovementSpeed = _Speed;
}

Bullet::~Bullet()
{
    
}

// FloatReact will return the bounds/positions of the sprite in coordinaate system and will enable access of them
const sf::FloatRect Bullet::getBounds() const
{
    
    return shape.getGlobalBounds();
}

//move functions will update the movement of the shape.
void Bullet::update()
{
    shape.move(this->MovementSpeed * this->direction);
}


//reset the bullet
void Bullet::render(sf::RenderTarget* target){
    target->draw(shape);
}



/*      ------TODO------ inside game class which is running the whole game
 1.  create a vector of bullets
     std::vector<Bullets*> bulletes // Bullets* to conserve the memory
 2.  In the game class under the update(), create the bullet at the position of the player and then push into a bulletes vector
 3. draw the bullet under render().
  for( auto * bullet : this-> bullets)
 {
    bullet-> render (this->window);
 {
 4.  Create a delete buttet to free up memory
    for( auto *i : this-> bullet )
    {
    delete i;
    }
 */




    


