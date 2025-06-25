

#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <resourceManager.hpp>

class Engine {
public:
    ResourceManager* resourceManager;
    float DeltaTime;

private:
    sf::RenderWindow* sf_Window;
    sf::Clock* sf_Clock;

    bool is_MetricsWindowOpened;
    bool is_AboutImGuiWindowOpened;
    bool is_MenuBarShown;

public:
    Engine();
    ~Engine();

    void createWindow(sf::Vector2u size, std::string title);
    bool initRenderer();
    bool update();
    void render();
    bool isOpen();
    sf::RenderWindow* getWindow();

private:
    void imguiDraw();
    void sfmlDraw();
};