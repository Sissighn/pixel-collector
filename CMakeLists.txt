cmake_minimum_required(VERSION 3.16)
project(TinyCollector)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(game
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Coin.cpp
)

target_link_libraries(game SFML::Graphics SFML::Window SFML::System)