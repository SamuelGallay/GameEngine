cmake_minimum_required(VERSION 3.14)
project(GameEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(GameEngine Example/main.cpp Engine/State.cpp Engine/State.h Engine/GameEngine.cpp Engine/GameEngine.h Example/MenuState.cpp Example/MenuState.h Engine/ResourceHolder.h Example/BrownianState.cpp Example/BrownianState.h Engine/Button.cpp Engine/Button.h)

target_link_libraries(GameEngine sfml-graphics)