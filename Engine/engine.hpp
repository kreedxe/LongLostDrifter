

#pragma once

#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>


class Engine {

private:
    sf::RenderWindow window;
    sf::Clock clock;

public:
    Engine();
    ~Engine();

    bool init();
    bool update();
    void draw();

    bool isOpen();

};