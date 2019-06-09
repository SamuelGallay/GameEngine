//
// Created by Samuel Gallay on 2019-06-02.
//

#ifndef GAMEENGINE_BROWNIANSTATE_H
#define GAMEENGINE_BROWNIANSTATE_H

#include "../Engine/State.h"
#include <vector>

class BrownianState : public State{
public:
    virtual void update(const float dt);

    virtual void handleEvent(sf::Event event);

    virtual void draw();

    virtual void initialize();

private:
    int Nparticles;
    sf::CircleShape bigParticle;
    std::vector<sf::Vector2f> velocity;
    sf::VertexArray list;
    sf::Vector2f bigSpeed;
    sf::VertexArray path;
};


#endif //GAMEENGINE_BROWNIANSTATE_H
