#include "Game.h"
#include <cstdlib>
#include <cmath>

Game::Game() :
window(sf::VideoMode({800,600}), "Tiny Collector")
{
    
    score = 0;

    coins.push_back(Coin(200,200));

    font.openFromFile("../assets/PixelifySans-VariableFont_wght.ttf");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({10,10});
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
    deltaTime = clock.restart().asSeconds();

    player.handleInput(deltaTime);
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
            scoreText.setString("Score: " + std::to_string(score));

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

    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);

    window.display();
}