#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h" 
class Coin : public Entity
{
public:
    Coin(float x, float y);

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() const;
    float getRadius() const;

private:
    sf::CircleShape shape;
};