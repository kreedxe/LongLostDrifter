cmake_minimum_required(VERSION 3.30)
project(SFML-IMGUI-GAME 
        VERSION 0.0.1
        LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.91.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG v3.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui-SFML)

set(SOURCES
    Engine/engine.cpp
    Engine/player.cpp
    Engine/resourceManager.cpp

    TheGame/main.cpp
)

add_executable(GameBinary ${SOURCES})

target_compile_features(GameBinary PRIVATE cxx_std_17)
target_link_libraries(GameBinary PRIVATE SFML::Graphics ImGui-SFML::ImGui-SFML)
target_include_directories(GameBinary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Engine/)