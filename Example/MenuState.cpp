//
// Created by Samuel Gallay on 2019-06-02.
//

#include "MenuState.h"
#include "BrownianState.h"
#include "../Engine/GameEngine.h"

void MenuState::update(const float dt) {
    sf::Vector2f mousePositionFloat = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    if (rectangle.getGlobalBounds().contains(mousePositionFloat))
        rectangle.setFillColor(sf::Color(100, 100, 100));
    else
        rectangle.setFillColor(sf::Color::Black);
}

void MenuState::handleEvent(sf::Event event) {
    if (event.type == sf::Event::Closed ||
        (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        window->close();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        stateEngine->buildState<BrownianState>();
    if (event.type == sf::Event::MouseButtonPressed){
        sf::Vector2f mousePositionFloat = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
        if (rectangle.getGlobalBounds().contains(mousePositionFloat))
            stateEngine->buildState<BrownianState>();
    }

}

void MenuState::draw(){
    window->draw(rectangle);
    window->draw(circle);
    window->draw(text);
}

void MenuState::initialize() {
    circle.setRadius(100.f);
    text.setString("Hello World !");
    text.setPosition(300, 200);
    text.setFont(holder->font.get("FiraSans-Light.otf"));
    auto flRect = text.getGlobalBounds();
    rectangle.setPosition(flRect.left - 20, flRect.top - 20);
    rectangle.setSize(sf::Vector2f(flRect.width + 40, flRect.height + 40));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(3.f);
}
