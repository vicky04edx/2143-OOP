#ifndef GRID_CLASS_HPP
#define GRID_CLASS_HPP

// Include the necessary headers for SFML graphics and the vector container
#include <SFML/Graphics.hpp>
#include <vector>

// Grid class definition
// Represents a 2D grid of cells with customizable dimensions, sizes, and spacing
class Grid {
public:
    // Constructor
    // Initializes the grid with the specified number of rows, columns, cell size, spacing, and starting position
    Grid(int rows, int cols, float cellSize, float cellSpacing, float startX, float startY);

    // Draws the grid on the given SFML window
    void draw(sf::RenderWindow& window) const;

    // Updates the value of a specific column in the grid
    void update(int col, int value);

    // Returns a constant reference to the vector of column values
    const std::vector<int>& getColumnValues() const;

private:
    // Vector of SFML rectangle shapes representing the cells in the grid
    std::vector<sf::RectangleShape> gridCells;

    // Vector storing integer values associated with each column of the grid
    std::vector<int> columnValues;

    // Number of rows and columns in the grid
    int rows, cols;

    // Size of each cell, spacing between cells, and starting position of the grid
    float cellSize, cellSpacing, startX, startY;
};

#endif // GRID_CLASS_HPP