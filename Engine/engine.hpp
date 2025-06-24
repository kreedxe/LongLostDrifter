

#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>

class Engine {
 private:
  sf::RenderWindow sf_Window;
  sf::Clock sf_Clock;

  bool is_MetricsWindowOpened;
  bool is_AboutImGuiWindowOpened;
  bool is_MenuBarShown;

 public:
  Engine(sf::Vector2u window_size, std::string window_title);
  ~Engine();

  bool init();
  bool update();
  void render();
  bool isOpen();
  sf::RenderWindow &getWindow();

 private:
  void imguiDraw();
  void sfmlDraw();
};