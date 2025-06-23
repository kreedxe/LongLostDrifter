

#pragma once

#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>


class Engine {

// private attributes
private:
    sf::RenderWindow window;
    sf::Clock clock;
    
    bool isMetricsWindowOpened;
    bool isAboutImGuiWindowOpened;

// public methods
public:
    Engine();
    ~Engine();

    bool init();
    bool update();
    void render();

    bool isOpen();
    sf::RenderWindow& getWindow();

// private methods
private:
    void imguiDraw();
    void sfmlDraw();

};