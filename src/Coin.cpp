#include "Coin.h"

Coin::Coin(float x, float y)
{
    shape.setRadius(15.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition({x, y});
}

void Coin::update(float deltaTime)
{
}

void Coin::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Coin::getPosition() const
{
    return shape.getPosition();
}

float Coin::getRadius() const
{
    return shape.getRadius();
}