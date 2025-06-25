

#include "engine.hpp"

Engine::Engine()
    : sf_Window(nullptr),
      sf_Clock(nullptr),
      is_MetricsWindowOpened(false),
      is_AboutImGuiWindowOpened(false),
      is_MenuBarShown(false),
      resourceManager(new ResourceManager()) {}

Engine::~Engine() {
    delete sf_Window;
    delete sf_Clock;
    delete resourceManager;
}

void Engine::createWindow(sf::Vector2u size, std::string title) {
    sf_Window =
        new sf::RenderWindow(sf::VideoMode(size), title, sf::Style::Close);
    sf_Clock = new sf::Clock;
    sf_Window->setFramerateLimit(60);
}

bool Engine::initRenderer() {
    if (!ImGui::SFML::Init(*sf_Window)) return false;

    return true;
}

bool Engine::update() {
    // hadle events
    while (const auto sf_Event = sf_Window->pollEvent()) {
        ImGui::SFML::ProcessEvent(*sf_Window, *sf_Event);

        // check for window close event
        if (sf_Event->is<sf::Event::Closed>()) {
            sf_Window->close();
            ImGui::SFML::Shutdown();
            return false;
        }

        // check for menu bar show/hide event
        if (sf_Event->is<sf::Event::KeyReleased>()) {
            const auto& key = sf_Event->getIf<sf::Event::KeyReleased>();

            if (key->code == sf::Keyboard::Key::Tab) {
                if (is_MenuBarShown) {
                    is_MenuBarShown = false;
                } else {
                    is_MenuBarShown = true;
                }
            }
        }
    }

    ImGui::SFML::Update(*sf_Window, sf_Clock->restart());

    imguiDraw();
    sf_Window->clear();
    sfmlDraw();
    return true;
}

void Engine::render() {
    ImGui::SFML::Render(*sf_Window);
    sf_Window->display();
}

void Engine::imguiDraw() {
    // top menu bar
    if (is_MenuBarShown) {
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Engine")) {
                ImGui::MenuItem("Settings");
                ImGui::MenuItem("About TheGame");
                ImGui::MenuItem("About ImGUI", NULL,
                                &is_AboutImGuiWindowOpened);
                ImGui::MenuItem("Quit");
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Tools")) {
                ImGui::MenuItem("Metrics", NULL, &is_MetricsWindowOpened);
                ImGui::MenuItem("Tool 2");
                ImGui::MenuItem("Tool 3");
                ImGui::MenuItem("Tool 4");
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }

    if (is_MetricsWindowOpened) {
        ImGui::ShowMetricsWindow(&is_MetricsWindowOpened);
    }
    if (is_AboutImGuiWindowOpened) {
        ImGui::ShowAboutWindow(&is_AboutImGuiWindowOpened);
    }
}

void Engine::sfmlDraw() {}

bool Engine::isOpen() { return sf_Window->isOpen(); }

sf::RenderWindow* Engine::getWindow() { return sf_Window; }