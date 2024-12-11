#ifndef GRID_HANDLER_HPP
#define GRID_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class GridHandler {
public:
    GridHandler(float startX, float startY, int rows, int cols, float cellSize, float cellSpacing);

    void draw(sf::RenderWindow& window) const;
    bool placeValue(int column, int value);
    int getColumnValue(int column) const;

private:
    struct Cell {
        sf::RectangleShape shape;
        int value;
    };

    std::vector<std::vector<Cell>> grid;
    int rows;
    int cols;
};

#endif
