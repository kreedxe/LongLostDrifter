cmake_minimum_required(VERSION 3.30)
project(proj-LongLostDrifter 
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

set (HEADERS)

add_executable(LongLostDrifter ${SOURCES})

target_compile_features(LongLostDrifter PRIVATE cxx_std_17)
target_link_libraries(LongLostDrifter PRIVATE SFML::Graphics ImGui-SFML::ImGui-SFML)
target_include_directories(LongLostDrifter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Engine/)

# List of all source files you want to format
file(GLOB_RECURSE CLANG_FORMAT_FILES
    "${CMAKE_SOURCE_DIR}/Engine/*.cpp"
    "${CMAKE_SOURCE_DIR}/Engine/*.hpp"
    "${CMAKE_SOURCE_DIR}/TheGame/*.cpp"
    "${CMAKE_SOURCE_DIR}/TheGame/*.hpp"
)

# Optional: Path to clang-format (leave empty to use system default)
find_program(CLANG_FORMAT_EXE NAMES clang-format)

if (CLANG_FORMAT_EXE)
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXE}
                -i
                -style=file
                ${CLANG_FORMAT_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting all source files with clang-format"
    )
else()
    message(WARNING "clang-format not found. The 'format' target will not be available.")
endif()