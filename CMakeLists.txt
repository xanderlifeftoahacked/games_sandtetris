cmake_minimum_required(VERSION 3.25)
project(FruitNinja VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)


find_package(SFML COMPONENTS system window graphics audio)
find_package(ImGui-SFML)
find_package(imgui CONFIG REQUIRED)

# find_package(imgui CONFIG REQUIRED)

add_executable(game src/game.cpp)


target_include_directories(game PRIVATE "${PROJECT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/lib")
target_compile_definitions(game PRIVATE PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
target_compile_definitions(game PRIVATE RESOURCE_PATH="${PROJECT_SOURCE_DIR}/resources/")


target_link_libraries(game
  PRIVATE ImGui-SFML::ImGui-SFML
  PRIVATE ${SFML_LIBRARIES}
  PRIVATE ${SFML_DEPENDENCIES}
  )
