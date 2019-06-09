//
// Created by Samuel Gallay on 2019-06-02.
//

#include "BrownianState.h"
#include "../Engine/GameEngine.h"
#include <cmath>


using namespace std;

float norme(sf::Vector2f v) { return sqrt(v.x * v.x + v.y * v.y); }

void BrownianState::update(const float dt) {
    for (int i = 0; i < list.getVertexCount(); i++) {
        sf::Vector2f pos = list[i].position;
        if (pos.x < 0)
            velocity[i].x = abs(velocity[i].x);
        if (pos.x > window->getSize().x)
            velocity[i].x = -abs(velocity[i].x);
        if (pos.y < 0)
            velocity[i].y = abs(velocity[i].y);
        if (pos.y > window->getSize().y)
            velocity[i].y = -abs(velocity[i].y);
        if (norme(pos - bigParticle.getPosition()) < bigParticle.getRadius()) {
            bigSpeed += velocity[i] * 0.1f;
            sf::Vector2f un = (pos - bigParticle.getPosition());
            un /= norme(un);
            sf::Vector2f ut(-un.y, un.x);
            float t = (velocity[i].y - velocity[i].x / un.x * un.y) /
                      (ut.y - ut.x / un.x * un.y);
            float n = (velocity[i].x - t * ut.x) / un.x;
            velocity[i] = -n * un + t * ut;
            list[i].position += ((pos - bigParticle.getPosition()) * 0.5f);
        }
        list[i].position += (velocity[i] * dt);
    }
    sf::Vector2f pos = bigParticle.getPosition();
    float radius = bigParticle.getRadius();
    if (pos.x - radius < 0)
        bigSpeed.x = abs(bigSpeed.x);
    if (pos.x + radius > window->getSize().x)
        bigSpeed.x = -abs(bigSpeed.x);
    if (pos.y - radius < 0)
        bigSpeed.y = abs(bigSpeed.y);
    if (pos.y + radius > window->getSize().y)
        bigSpeed.y = -abs(bigSpeed.y);
    bigParticle.move(bigSpeed * dt);

    path.append(sf::Vertex(bigParticle.getPosition(), sf::Color::Red));
}

void BrownianState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::Closed)
        window->close();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateEngine->popState();
}

void BrownianState::draw() {
    sf::FloatRect visibleArea(0.f, 0.f, window->getSize().x, window->getSize().y);
    window->setView(sf::View(visibleArea));
    window->draw(bigParticle);
    window->draw(list);
    window->draw(path);
}

void BrownianState::initialize() {
    Nparticles = 10000;
    list = sf::VertexArray(sf::Points, Nparticles);
    for (int i = 0; i < list.getVertexCount(); i++) {
        list[i].position =
                sf::Vector2f(rand() % window->getSize().x, rand() % window->getSize().y);
    }

    velocity = vector<sf::Vector2f>(Nparticles);
    for (int i = 0; i < velocity.size(); i++) {
        velocity[i] = sf::Vector2f(rand() % 200 - 100, rand() % 200 - 100);
    }

    bigParticle.setRadius(20);
    bigParticle.setOrigin(bigParticle.getRadius(), bigParticle.getRadius());
    bigParticle.setFillColor(sf::Color::Red);
    bigParticle.setPosition(window->getSize().x * 0.5f, window->getSize().y * 0.5f);
    bigSpeed = sf::Vector2f(0.f, 0.f);

    path = sf::VertexArray(sf::LineStrip);
}
