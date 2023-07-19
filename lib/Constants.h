#pragma once
#include <SFML/Graphics/Color.hpp>
#include <vector>

inline constexpr int window_width = 400;
inline constexpr int window_height = 800;
inline constexpr float grid_step = 40.0f;
inline constexpr float moving_speed = 40.0f;
inline constexpr float gravity = 10.0f;

inline const std::vector<sf::Color> colors = {
    sf::Color::Red, sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta};
enum class Colors { Empty = -1, Red, Yellow, Cyan, Magenta };
inline std::vector<std::vector<Colors>>
    grid(window_height, std::vector<Colors>(window_width, Colors::Empty));

inline constexpr int number_of_tetraminos = 7;
inline constexpr int number_of_rotations = 4;
using TetraminoArr = std::vector<std::vector<int>>;
inline const std::vector<TetraminoArr> tetraminos = {
    {{1, 1}, {1, 1}},
    {{1, 1}, {1, 1}},
    {{1, 1}, {1, 1}},
    {{1, 1}, {1, 1}},

    // {{1, 1, 1, 0, 1},
    //  {0, 0, 1, 0, 1},
    //  {1, 1, 1, 1, 1},
    //  {1, 0, 1, 0, 0},
    //  {1, 0, 1, 1, 1}},
    //
    // {{1, 1, 1, 0, 1},
    //  {0, 0, 1, 0, 1},
    //  {1, 1, 1, 1, 1},
    //  {1, 0, 1, 0, 0},
    //  {1, 0, 1, 1, 1}},
    //
    // {{1, 1, 1, 0, 1},
    //  {0, 0, 1, 0, 1},
    //  {1, 1, 1, 1, 1},
    //  {1, 0, 1, 0, 0},
    //  {1, 0, 1, 1, 1}},
    //
    // {{1, 1, 1, 0, 1},
    //  {0, 0, 1, 0, 1},
    //  {1, 1, 1, 1, 1},
    //  {1, 0, 1, 0, 0},
    //  {1, 0, 1, 1, 1}},

    {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}},
    {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},

    {{0, 1, 0}, {1, 1, 1}, {0, 0, 0}},
    {{0, 1, 0}, {0, 1, 1}, {0, 1, 0}},
    {{0, 0, 0}, {1, 1, 1}, {0, 1, 0}},
    {{0, 1, 0}, {1, 1, 0}, {0, 1, 0}},

    {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}},
    {{0, 1, 1}, {0, 1, 0}, {0, 1, 0}},
    {{0, 0, 0}, {1, 1, 1}, {0, 0, 1}},
    {{0, 1, 0}, {0, 1, 0}, {1, 1, 0}},

    {{0, 0, 1}, {1, 1, 1}, {0, 0, 0}},
    {{0, 1, 0}, {0, 1, 0}, {0, 1, 1}},
    {{0, 0, 0}, {1, 1, 1}, {1, 0, 0}},
    {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}},

    {{0, 1, 1}, {1, 1, 0}, {0, 0, 0}},
    {{0, 1, 0}, {0, 1, 1}, {0, 0, 1}},
    {{0, 0, 0}, {0, 1, 1}, {1, 1, 0}},
    {{0, 1, 1}, {1, 1, 0}, {0, 0, 0}},

    {{1, 1, 0}, {0, 1, 1}, {0, 0, 0}},
    {{0, 0, 1}, {0, 1, 1}, {0, 1, 0}},
    {{0, 0, 0}, {1, 1, 0}, {0, 1, 1}},
    {{0, 1, 0}, {1, 1, 0}, {1, 0, 0}}};
