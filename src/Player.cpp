#include "Player.h"

Player::Player()
{
    shape.setRadius(30.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({400,300});

    speed = 0.3f;
}

void Player::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        shape.move({0, -speed});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        shape.move({0, speed});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        shape.move({-speed, 0});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        shape.move({speed, 0});
}

void Player::update()
{
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Player::getPosition() const
{
    return shape.getPosition();
}

float Player::getRadius() const
{
    return shape.getRadius();
}