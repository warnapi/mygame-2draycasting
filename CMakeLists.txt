cmake_minimum_required(VERSION 3.25)
project(person_games)

set(CMAKE_CXX_STANDARD 23)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "J:/games/lib/SFML64/SFML-3.1.0/lib/cmake/SFML")

find_package(SFML 3.1 COMPONENTS Graphics Window System REQUIRED)

add_executable(Server WIN32 src/server/mainOfServer.cpp
        src/server/mainOfServer.cpp
        src/server/connection.cpp
        src/server/connection.h
        src/general/udp.cpp
        src/general/udp.h)

add_executable(person_games
        src/client/mainOfClient.cpp
        src/general/player.cpp
        src/general/player.h
        src/general/map.cpp
        src/general/map.h
        src/general/game_const.h
        src/client/game.cpp
        src/client/game.h
        src/client/miniMapRender.cpp
        src/client/miniMapRender.h
        src/client/CameraRender.cpp
        src/client/CameraRender.h
        src/general/rayInfo.h
        src/general/udp.cpp
        src/general/udp.h
)

target_link_libraries(person_games PRIVATE SFML::Graphics SFML::Window SFML::System)
