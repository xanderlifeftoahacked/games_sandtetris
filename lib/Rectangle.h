#pragma once
#include "Constants.h"
#include "PressedButtons.h"
#include "Utils.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <vector>

class Rectangle {
public:
  struct Pair {
    int x;
    int y;
  };

  Rectangle(sf::Color _color, int _x_pos, int _y_pos, sf::RenderWindow *_window,
            int _size = static_cast<int>(moving_speed))
      : color{_color}, x_pos{_x_pos}, y_pos{_y_pos}, size{_size},
        rectangle{sf::Vector2f(_size, _size)}, window{_window} {
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(3);
    rectangle.setPosition(x_pos, y_pos);
  };

  // bool is_moveable() {
  //   return x_pos + size < window_width && x_pos - size > 0 &&
  //          y_pos + size < window_height && y_pos - size > 0;
  // }

  void kill() {
    is_idle = true;
    for (int i = y_pos; i < y_pos + size; i++) {
      for (int j = x_pos; j < x_pos + size; j++) {
        grid[i][j] = get_color(color);
      }
    }
  }

  void check_collision() {
    if (y_pos >= window->getSize().y - size && !is_idle) {
      is_idle = true;
      for (int i = y_pos; i < y_pos + size; i++) {
        for (int j = x_pos; j < x_pos + size; j++) {
          grid[i][j] = get_color(color);
        }
      }
    }
  }
  // TODO
  void fall() {
    return;
    check_collision();
    if (!is_idle) {
      rectangle.setPosition(x_pos, y_pos += gravity / 2);

      // for (int i = x_pos; i < x_pos + size; i++) {
      //   if (grid[y_pos + size][i] != Colors::Empty) {
      //     is_idle = true;
      //     for (int i = y_pos; i < y_pos + size; i++) {
      //       for (int j = x_pos; j < x_pos + size; j++) {
      //         grid[i][j] = get_color(color);
      //       }
      //     }
      //     break;
      //   }
      // }
    }
  }

  void move(const float moving_speed, sf::Time dt, Pressed buttons) {
    for (int i = x_pos; i < x_pos + size; i++) {
      if (grid[y_pos + size][i] != Colors::Empty) {
        is_idle = true;
        for (int i = y_pos; i < y_pos + size; i++) {
          for (int j = x_pos; j < x_pos + size; j++) {
            grid[i][j] = get_color(color);
          }
        }
        break;
      }
    }
    if (!is_idle) {
      if (buttons.left && x_pos > 0) {
        rectangle.setPosition(x_pos -= (moving_speed * 1), y_pos);
      } else if (buttons.right && x_pos + size < window_width) {
        rectangle.setPosition(x_pos += (moving_speed * 1), y_pos);
      } else if (buttons.down && y_pos + size < window_height) {
        rectangle.setPosition(x_pos, y_pos += (moving_speed * 1));
      } else if (buttons.up && y_pos > 0) {
        rectangle.setPosition(x_pos, y_pos -= (moving_speed * 1));
      }
    }

    check_collision();
  };

  const void show() { window->draw(rectangle); }
  const Pair get_pos() { return Pair{x_pos, y_pos}; }
  const bool get_is_idle() { return is_idle; }
  void set_is_idle(bool val) { is_idle = val; }

private:
  const sf::Color color;
  const int size;
  int x_pos, y_pos;
  bool is_idle = false;
  sf::RenderWindow *window = nullptr;
  sf::RectangleShape rectangle;
};
