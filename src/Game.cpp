#include "Game.h"
#include <cmath>

Game::Game() :
window(sf::VideoMode({800,600}), "Tiny Collector")
{
    state = GameState::Menu;
    score = 0;

    player.setWindowSize(window.getSize());

    font.openFromFile("../assets/PixelifySans-VariableFont_wght.ttf");

    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({10,10});

    rng = std::mt19937(std::random_device{}());
    xDist = std::uniform_real_distribution<float>(50,750);
    yDist = std::uniform_real_distribution<float>(50,550);

    entities.push_back(std::make_unique<Coin>(200,200));
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

    if (state == GameState::Menu)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            state = GameState::Playing;
        }
    }
}

void Game::update()
{
    deltaTime = clock.restart().asSeconds();

    if (state != GameState::Playing)
        return;

    player.handleInput(deltaTime);
    player.update(deltaTime);

    auto playerPos = player.getPosition();

    for (size_t i = 0; i < entities.size(); i++)
    {
        Coin* coin = dynamic_cast<Coin*>(entities[i].get());

        if (!coin)
            continue;

        auto coinPos = coin->getPosition();

        float dx = playerPos.x - coinPos.x;
        float dy = playerPos.y - coinPos.y;

        float distance = std::sqrt(dx * dx + dy * dy);

        if (distance < player.getRadius() + coin->getRadius())
        {
            score++;

            entities.erase(entities.begin() + i);

            entities.push_back(
                std::make_unique<Coin>(xDist(rng), yDist(rng))
            );

            break;
        }
    }

    scoreText.setString("Score: " + std::to_string(score));
}

void Game::render()
{
    window.clear();

    if (state == GameState::Menu)
    {
        scoreText.setString("Press ENTER to start");
        window.draw(scoreText);
    }
    else if (state == GameState::Playing)
    {
        player.draw(window);

        for (auto& entity : entities)
        {
            entity->draw(window);
        }

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);
    }
    else if (state == GameState::GameOver)
    {
        scoreText.setString("Game Over");
        window.draw(scoreText);
    }

    window.display();
}