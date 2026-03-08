#include "Game.h"
#include <cstdlib>

Game::Game() :
window(sf::VideoMode({800,600}), "Tiny Collector")
{
    score = 0;

    coins.push_back(Coin(200,200));
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update()
{
    player.handleInput();
    player.update();

    auto playerPos = player.getPosition();

    for (size_t i = 0; i < coins.size(); i++)
    {
        auto coinPos = coins[i].getPosition();

        float dx = playerPos.x - coinPos.x;
        float dy = playerPos.y - coinPos.y;

        float distance = std::sqrt(dx*dx + dy*dy);

        if (distance < player.getRadius() + coins[i].getRadius())
        {
            score++;
            coins.erase(coins.begin() + i);

            float x = rand() % 700;
            float y = rand() % 500;

            coins.push_back(Coin(x,y));

            break;
        }
    }
}

void Game::render()
{
    window.clear();

    player.draw(window);

    for (auto& coin : coins)
        coin.draw(window);

    window.display();
}