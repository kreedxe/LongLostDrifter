

#include "engine.hpp"


Engine::Engine():
window(sf::VideoMode({1400, 700}), "SFML + ImGUI Game", sf::Style::Close),
isMetricsWindowOpened(false),
isAboutImGuiWindowOpened(false)
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
    
    imguiDraw();
    window.clear();
    sfmlDraw();
    return true;
}


void Engine::render()
{
    ImGui::SFML::Render(window);
    window.display();
}


void Engine::imguiDraw()
{
    // top menu bar
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Engine")) {
            ImGui::MenuItem("Settings");
            ImGui::MenuItem("About TheGame");
            ImGui::MenuItem("About ImGUI", NULL, &isAboutImGuiWindowOpened);
            ImGui::MenuItem("Quit");
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Tools")) {
            ImGui::MenuItem("Metrics", NULL, &isMetricsWindowOpened);
            ImGui::MenuItem("Tool 2");
            ImGui::MenuItem("Tool 3");
            ImGui::MenuItem("Tool 4");
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if (isMetricsWindowOpened) {ImGui::ShowMetricsWindow(&isMetricsWindowOpened);}
    if (isAboutImGuiWindowOpened) {ImGui::ShowAboutWindow(&isAboutImGuiWindowOpened);}
}


void Engine::sfmlDraw()
{

}


bool Engine::isOpen()
{
    return window.isOpen();
}


sf::RenderWindow& Engine::getWindow()
{
    return window;
}