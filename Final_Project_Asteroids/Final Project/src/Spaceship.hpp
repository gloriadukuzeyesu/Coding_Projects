//
//  Spaceship.hpp
//  testSFML
//
//  Created by Lakshay Santosh Kucheriya on 9/21/22.
//
#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Spaceship{
    
private:
    
    sf::Texture texture ;
    sf::Sprite sprite ;
    
    float MovementSpeed ;
    
    float ShootCoolDown ;
    float ShootCoolDownMax;
    
    int hp ;
    int hpMax;
    
    void InitializeTexture() ;
    void InitializeSprite() ;
    void InitializeVariables() ;
    
    
public:
    Spaceship() ;
    ~Spaceship() ;
    
    //Accessor
    const sf::Vector2f& getPos() const ;
    const sf::FloatRect getBounds() const ;
    const int& getHP() const ;
    const int& getHPmax() const ;
    
    
    //Modifiers
    void setPosition(const sf::Vector2f pos);
    void SetPosition(const float x, const float y);
    void SetHp(const int hp) ;
    void Hplost(const int value) ;
    
    
    
    // Functions
    void move(const float x_dir, const float y_dir);
    bool canShoot() ;
    void updateShoot() ;
    void update() ;
    void render(sf::RenderTarget& target) ;
                    // Render Target defines the common behaviour of all the 2D Render targets in the Graphics module
    
    
};


