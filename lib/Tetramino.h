#include "Constants.h"
#include "PressedButtons.h"
#include "Rectangle.h"
#include "Utils.h"
#include "iterator"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>
#include <vector>

class Tetramino {
public:
  Tetramino(sf::Color _color, sf::RenderWindow *_window, int _x_pos, int _y_pos)
      : color{_color}, window{_window}, x_pos{_x_pos}, y_pos{_y_pos} {

    int tetramino_number = get_random(0, number_of_tetraminos - 1);
    tetr_rotations = std::vector<TetraminoArr>(
        tetraminos.begin() + tetramino_number * number_of_rotations,
        tetraminos.begin() + tetramino_number * number_of_rotations +
            number_of_rotations);
    cur_tetr = tetr_rotations[cur_rot];
    for (int y = 0; y < cur_tetr.size(); y++) {
      for (int x = 0; x < cur_tetr.size(); x++) {
        if (cur_tetr[y][x] == 1) {
          Rectangle *rect =
              new Rectangle(color, x_pos + size * x, y_pos + size * y, window);
          rectangles.push_back(rect);
        }
      }
    }
  }

  ~Tetramino() {
    for (auto rect : rectangles) {
      if (rect == nullptr)
        continue;
      delete rect;
    }
  }

  void move(const float moving_speed, sf::Time dt, Pressed buttons) {
    if (buttons.left && x_pos > 0) {
      x_pos -= (moving_speed * 1);
    } else if (buttons.right && x_pos + size < window_width) {
      x_pos += (moving_speed * 1);
    } else if (buttons.down && y_pos + size < window_height) {
      y_pos += (moving_speed * 1);
    }

    if (!buttons.up) {
      for (auto rect : rectangles) {
        if (!rect->get_is_idle())
          rect->move(moving_speed, dt, buttons);
        for (auto rect : rectangles) {
          if (rect->get_is_idle()) {
            std::for_each(rectangles.begin(), rectangles.end(),
                          [](Rectangle *rect) { rect->kill(); });
            std::cout << "IDLE" << '\n';
          }
        }
      }
      return;
    }

    std::for_each(rectangles.begin(), rectangles.end(),
                  [](Rectangle *rect) { delete rect; });
    rectangles.clear();
    cur_tetr = tetr_rotations[++cur_rot % number_of_rotations];
    for (int y = 0; y < cur_tetr.size(); y++) {
      for (int x = 0; x < cur_tetr.size(); x++) {
        if (cur_tetr[y][x] == 1) {
          Rectangle *rect =
              new Rectangle(color, x_pos + size * x, y_pos + size * y, window);
          rectangles.push_back(rect);
        }
      }
    }
  };

  void updaterects() {
    for (auto rect : rectangles) {
      if (rect == nullptr)
        continue;
      if (rect->get_is_idle() == true) {
        delete rect;
        rect = nullptr;
      }
    }
  }

  bool get_is_idle() {
    for (auto rect : rectangles) {
      if (rect->get_is_idle()) {
        std::for_each(rectangles.begin(), rectangles.end(),
                      [](Rectangle *rect) { rect->kill(); });
        std::cout << "IDLE" << '\n';

        return true;
      }
    }
    return false;
  }

  void show() {
    for (auto rect : rectangles) {
      if (!rect->get_is_idle())
        rect->show();
    }
  }

private:
  int x_pos, y_pos;
  int cur_rot = 0;
  int size = static_cast<int>(grid_step);
  sf::RenderWindow *window = nullptr;
  std::vector<TetraminoArr> tetr_rotations;
  TetraminoArr cur_tetr;
  const sf::Color color;
  std::vector<Rectangle *> rectangles;
};
