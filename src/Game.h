#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Coin.h"
#include <vector>

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

    std::vector<Coin> coins;
    int score;
};