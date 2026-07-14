cmake_minimum_required(VERSION 3.25)
project(person_games)

set(CMAKE_CXX_STANDARD 23)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "J:/games/lib/SFML64/SFML-3.1.0/lib/cmake/SFML")

find_package(SFML 3.1 COMPONENTS Graphics Window System REQUIRED)

add_executable(person_games
        src/main.cpp
        src/player.cpp
        src/player.h
        src/map.cpp
        src/map.h
        src/game_const.h
        src/game.cpp
        src/game.h
        src/miniMapRender.cpp
        src/miniMapRender.h
        src/CameraRender.cpp
        src/CameraRender.h
)

target_link_libraries(person_games PRIVATE SFML::Graphics SFML::Window SFML::System)
