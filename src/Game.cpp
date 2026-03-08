#include "Game.h"

Game::Game() :
window(sf::VideoMode({800,600}), "Tiny Collector")
{
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
}

void Game::render()
{
    window.clear();
    player.draw(window);
    window.display();
}