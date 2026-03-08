#pragma once
#include <SFML/Graphics.hpp>

class Coin
{
public:
    Coin(float x, float y);

    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    float getRadius() const;

private:
    sf::CircleShape shape;
};