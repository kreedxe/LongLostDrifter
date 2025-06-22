

#include "engine.hpp"


Engine::Engine():
window(sf::VideoMode({1400, 700}), "SFML + ImGUI Game", sf::Style::Close)
{

}

Engine::~Engine()
{

}

bool Engine::init()
{
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
        return false;
    
    return true;
}

bool Engine::update()
{
    // check for close
    while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
                ImGui::SFML::Shutdown();
                return false;
            }
        }

    ImGui::SFML::Update(window, clock.restart());
    
    return true;
}

void Engine::draw()
{
    window.clear();

    //draw SFML objects here

    ImGui::SFML::Render(window);
    window.display();
}

bool Engine::isOpen()
{
    return window.isOpen();
}