

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 500}), 
                            "SFML + ImGUI Game",
                            sf::Style::Close);
    window.setFramerateLimit(60);
    if (!ImGui::SFML::Init(window))
        return -1;

    bool opened = true;
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
                ImGui::SFML::Shutdown();
                return 0;
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::SetNextWindowSize(ImVec2(200, 200));
        ImGui::Begin("About TheGame", &opened, ImGuiWindowFlags_NoResize);
        ImGui::End();

        window.clear();

        //draw SFML objects here

        ImGui::SFML::Render(window);
        window.display();
    }
}