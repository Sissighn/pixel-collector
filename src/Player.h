#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
    Player();

    void handleInput(float deltaTime);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    void setWindowSize(sf::Vector2u size);

    sf::Vector2f getPosition() const;
    float getRadius() const;

private:
    sf::CircleShape shape;
    float speed;

    sf::Vector2u windowSize;
};