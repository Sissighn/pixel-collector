#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void handleInput();
    void update();
    void draw(sf::RenderWindow & window);

    sf::Vector2f getPosition() const;
    float getRadius() const;

private:
    sf::CircleShape shape;
    float speed;
};