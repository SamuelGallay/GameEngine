#include "../Engine/GameEngine.h"
#include "MenuState.h"


int main() {
    auto engine = GameEngine::create();

    engine->buildState<MenuState>();
    engine->gameLoop();

    return 0;
}