#include "grid_class.hpp"

// Constructor for the Grid class.
// Initializes a grid of cells based on the given dimensions, cell size, spacing, and starting position.
Grid::Grid(int rows, int cols, float cellSize, float cellSpacing, float startX, float startY)
    : rows(rows),                     // Number of rows in the grid
      cols(cols),                     // Number of columns in the grid
      cellSize(cellSize),             // Size of each cell (width and height, assuming square cells)
      cellSpacing(cellSpacing),       // Space between adjacent cells
      startX(startX),                 // X-coordinate for the starting position of the grid
      startY(startY),                 // Y-coordinate for the starting position of the grid
      columnValues(cols, 0) {         // Initialize columnValues with zeros for each column

    // Loop through each row and column to create the grid cells
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Create a rectangle representing a grid cell
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

            // Set cell properties
            cell.setFillColor(sf::Color::White);        // Fill color of the cell
            cell.setOutlineColor(sf::Color::Black);    // Outline color of the cell
            cell.setOutlineThickness(2.f);            // Thickness of the cell outline

            // Set the position of the cell in the grid
            cell.setPosition(startX + col * (cellSize + cellSpacing),
                             startY + row * (cellSize + cellSpacing));

            // Add the cell to the gridCells vector
            gridCells.push_back(cell);
        }
    }
}

// Draws the grid on the provided SFML window.
void Grid::draw(sf::RenderWindow& window) const {
    // Iterate through each cell in the grid and draw it on the window
    for (const auto& cell : gridCells) {
        window.draw(cell);
    }
}

// Updates the value of a specific column.
// This can be used to track or modify data associated with columns in the grid.
void Grid::update(int col, int value) {
    columnValues[col] = value; // Update the value for the specified column index
}

// Returns a constant reference to the vector of column values.
// This allows read-only access to the current state of column values.
const std::vector<int>& Grid::getColumnValues() const {
    return columnValues;
}