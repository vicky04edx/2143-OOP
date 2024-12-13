#ifndef GRID_HANDLER_HPP
#define GRID_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Class to manage a 2D grid of cells for rendering and interaction
class GridHandler {
public:
    // Constructor
    // Initializes the grid with a given starting position, dimensions, cell size, and spacing
    GridHandler(float startX, float startY, int rows, int cols, float cellSize, float cellSpacing);

    // Draws the grid and any associated values onto the specified SFML window
    void draw(sf::RenderWindow& window) const;

    // Places a numerical value into the specified column
    // Returns true if successful, false if the column is full or invalid
    bool placeValue(int column, int value);

    // Retrieves the value of the first non-zero cell in the specified column
    // Returns -1 if the column is invalid or 0 if the column is empty
    int getColumnValue(int column) const;

private:
    // Internal structure to represent an individual cell
    struct Cell {
        sf::RectangleShape shape; // Graphical representation of the cell
        int value;                // Numerical value stored in the cell (default is 0)
    };

    std::vector<std::vector<Cell>> grid; // 2D grid of cells represented as a vector of vectors
    int rows;                            // Number of rows in the grid
    int cols;                            // Number of columns in the grid
};

#endif // GRID_HANDLER_HPP
