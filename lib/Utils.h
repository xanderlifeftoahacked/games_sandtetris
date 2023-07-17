#pragma once
#include "Constants.h"
#include <SFML/Graphics/Color.hpp>
#include <iterator>
#include <random>
#include <string>

inline std::string resPath(const std::string filename) {
  return std::string(RESOURCE_PATH + filename);
}

inline int get_random(const int l, const int r) {
  std::random_device rd;
  std::uniform_int_distribution<int> gen(l, r);
  return gen(rd);
}

inline sf::Color get_sfcolor(Colors color) {
  switch (color) {
  case Colors::Red:
    return sf::Color::Red;
    break;
  case Colors::Cyan:
    return sf::Color::Cyan;
    break;
  case Colors::Magenta:
    return sf::Color::Magenta;
    break;
  case Colors::Yellow:
    return sf::Color::Yellow;
    break;
  case Colors::Empty:
    return sf::Color::Black;
    break;
  default:
    return sf::Color::Black;
    break;
  }
}

inline Colors get_color(sf::Color color) {
  if (color == sf::Color::Cyan) {
    return Colors::Cyan;
  } else if (color == sf::Color::Red) {
    return Colors::Red;
  } else if (color == sf::Color::Yellow) {
    return Colors::Yellow;
  } else if (color == sf::Color::Magenta) {
    return Colors::Magenta;
  } else {
    return Colors::Empty;
  }
}

template <typename T> inline T random_element(const std::vector<T> vec) {
  return vec[get_random(0, vec.size() - 1)];
}

template <typename T>
inline void set_range(typename std::vector<T>::iterator l,
                      typename std::vector<T>::iterator r, T value) {
  while (l++ != r) {
    *l = value;
  }
}
