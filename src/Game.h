#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <random>

#include "Entity.h"
#include "Player.h"
#include "Coin.h"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;

    Player player;

    std::vector<std::unique_ptr<Entity>> entities;

    int score;

    sf::Font font;
    sf::Text scoreText{font};

    std::mt19937 rng;
    std::uniform_real_distribution<float> xDist;
    std::uniform_real_distribution<float> yDist;

    sf::Clock clock;
    float deltaTime;
};