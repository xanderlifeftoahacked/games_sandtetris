#pragma once
#include "Constants.h"
#include "PressedButtons.h"
#include "Rectangle.h"
#include "Tetramino.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class Game {
public:
  Game()
      : window{sf::VideoMode(window_width, window_height), "Satris"},
        tetr{new Tetramino(random_element(colors), &window, 120, 120)},
        buttons{false, false, false, false} {
    window.setVerticalSyncEnabled(true);
  }

  void get_event() {
    buttons.left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    buttons.right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    buttons.down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    buttons.up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
  }

  void updategrid() {
    std::vector<std::vector<Colors>> temp = grid;
    for (int i = window_height - 2; i > 0; --i) {
      for (int j = window_width - 2; j > 0; --j) {
        if (grid[i][j] != Colors::Empty)
          continue;

        if (grid[i - 1][j] != Colors::Empty) {
          std::swap(temp[i][j], temp[i - 1][j]);
        } else if (grid[i - 1][j + 1] != Colors::Empty) {
          std::swap(temp[i][j], temp[i - 1][j + 1]);
        } else if (grid[i - 1][j - 1] != Colors::Empty) {
          std::swap(temp[i][j], temp[i - 1][j - 1]);
        }
      }
    }
    grid = temp;
  }

  void checkline();

  void showsand() {
    sf::VertexArray vertices;
    for (int i = 0; i < window_height; i++) {
      for (int j = 0; j < window_width; j++) {
        if (grid[i][j] != Colors::Empty) {
          sf::Vertex vertex;
          vertex.color = get_sfcolor(grid[i][j]);
          vertex.position = sf::Vector2f(j, i);
          vertices.append(vertex);
        }
      }
    }
    window.draw(vertices);
  }

  void mainloop() {
    while (window.isOpen()) {
      sf::Event event;

      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          window.close();
        get_event();
        tetr->move(moving_speed, dt, buttons);
      }
      // tetr->fall();
      if (tetr->get_is_idle()) {
        delete tetr;
        tetr = new Tetramino(random_element(colors), &window, 200, 200);
      }

      window.clear();
      updategrid();
      showsand();
      tetr->show();
      window.display();
      dt = delta_clock.restart();
    }
  }

private:
  sf::Clock delta_clock;
  sf::Time dt;
  sf::RenderWindow window;
  Pressed buttons;
  Tetramino *tetr;
};
