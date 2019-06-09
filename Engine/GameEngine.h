//
// Created by Samuel Gallay on 2019-06-02.
//

#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

#include "State.h"

class GameEngine : public std::enable_shared_from_this<GameEngine> {
public:
    static std::shared_ptr<GameEngine> create();

    void popState();

    std::shared_ptr<State> currentState();

    void gameLoop();

    template <typename T>
    void buildState(){
        states.push_back(std::make_shared<T>());
        states.back()->build(shared_from_this(), window, holder);
        states.back()->initialize();
    }

private:
    GameEngine();

    std::shared_ptr<sf::RenderWindow> window;
    std::vector<std::shared_ptr<State>> states;
    std::shared_ptr<Holder> holder;
};


#endif //GAMEENGINE_GAMEENGINE_H
