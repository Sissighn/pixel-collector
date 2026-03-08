#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void handleInput();
    void update();
    void draw(sf::RenderWindow & window);

private:
    sf::CircleShape shape;
    float speed;
};