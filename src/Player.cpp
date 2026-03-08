#include "Player.h"

Player::Player()
{
    shape.setRadius(30.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({400,300});

    speed = 0.3f;
}

void Player::handleInput(float deltaTime)
{
    float move = speed * deltaTime * 300;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        shape.move({0, -move});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        shape.move({0, move});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        shape.move({-move, 0});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        shape.move({move, 0});
}

void Player::update(float deltaTime)
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