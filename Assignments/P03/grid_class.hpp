#ifndef GRID_CLASS_HPP
#define GRID_CLASS_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
public:
    Grid(int rows, int cols, float cellSize, float cellSpacing, float startX, float startY);

    void draw(sf::RenderWindow& window) const;
    void update(int col, int value);
    const std::vector<int>& getColumnValues() const;

private:
    std::vector<sf::RectangleShape> gridCells;
    std::vector<int> columnValues;
    int rows, cols;
    float cellSize, cellSpacing, startX, startY;
};

#endif // GRID_CLASS_HPP

