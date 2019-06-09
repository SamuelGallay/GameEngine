//
// Created by Samuel Gallay on 2019-06-02.
//

#include "GameEngine.h"

void GameEngine::popState() {
    states.pop_back();
}

std::shared_ptr<State> GameEngine::currentState() {
    if (states.empty())
        return nullptr;
    else
        return states.back();
}

void GameEngine::gameLoop() {
    sf::Clock clock;

    while (window->isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (currentState() == nullptr)
            continue;

        sf::Event event;
        while (window->pollEvent(event))
            currentState()->handleEvent(event);

        currentState()->update(dt);

        window->clear();
        currentState()->draw();
        window->display();
    }
}

GameEngine::GameEngine() {
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(800, 600), "GameEngine");
    window->setFramerateLimit(60);

    holder = std::make_shared<Holder>();
}

std::shared_ptr<GameEngine> GameEngine::create() {
    return std::shared_ptr<GameEngine>(new GameEngine());
}
