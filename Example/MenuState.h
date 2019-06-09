//
// Created by Samuel Gallay on 2019-06-02.
//

#ifndef GAMEENGINE_MENUSTATE_H
#define GAMEENGINE_MENUSTATE_H

#include "../Engine/State.h"

class MenuState : public State{
public:
    virtual void update(const float dt);

    virtual void handleEvent(sf::Event event);

    virtual void draw();

    virtual void initialize();

private:
    sf::CircleShape circle;
    sf::Text text;
    sf::RectangleShape rectangle;
};


#endif //GAMEENGINE_MENUSTATE_H
