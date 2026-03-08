#include "Player.h"
#include <algorithm>
#include <cmath>

Player::Player()
: texture("../assets/cat.png"),
  sprite(texture)
{
    texture.setSmooth(false);

    auto bounds = sprite.getLocalBounds();
    sprite.setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});

    sprite.setPosition({400,300});

    sprite.setScale({0.65f, 0.65f});

    speed = 90.f;
}

void Player::handleInput(float deltaTime)
{
    float move = speed * deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        sprite.move({0, -move});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        sprite.move({0, move});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        sprite.move({-move, 0});
        sprite.setScale({-0.65f, 0.65f});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        sprite.move({move, 0});
        sprite.setScale({0.65f, 0.65f});
    }
}

void Player::update(float deltaTime)
{
    auto pos = sprite.getPosition();

    auto bounds = sprite.getLocalBounds();
    auto scale = sprite.getScale();

    float width  = bounds.size.x * std::abs(scale.x);
    float height = bounds.size.y * std::abs(scale.y);

    float maxX = windowSize.x - width / 2.f;
    float maxY = windowSize.y - height / 2.f;

    float minX = width / 2.f;
    float minY = height / 2.f;

    float clampedX = std::clamp(pos.x, minX, maxX);
    float clampedY = std::clamp(pos.y, minY, maxY);

    sprite.setPosition({clampedX, clampedY});
}

void Player::setWindowSize(sf::Vector2u size)
{
    windowSize = size;
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}

float Player::getRadius() const
{
    return sprite.getGlobalBounds().size.x / 1.8f;
}