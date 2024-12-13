#include "GridHandler.hpp"

// Constructor for the GridHandler class
// Initializes the grid with specified dimensions, cell size, spacing, and start position
GridHandler::GridHandler(float startX, float startY, int rows, int cols, float cellSize, float cellSpacing)
    : rows(rows), cols(cols) {
    // Iterate over each row
    for (int row = 0; row < rows; ++row) {
        std::vector<Cell> rowCells; // Temporary container for cells in the current row

        // Iterate over each column
        for (int col = 0; col < cols; ++col) {
            Cell cell; // Create a new cell

            // Configure the cell's appearance and position
            cell.shape.setSize(sf::Vector2f(cellSize, cellSize));
            cell.shape.setPosition(startX + col * (cellSize + cellSpacing), startY + row * (cellSize + cellSpacing));
            cell.shape.setFillColor(sf::Color::White);
            cell.shape.setOutlineColor(sf::Color::Black);
            cell.shape.setOutlineThickness(2.f);
            cell.value = 0; // Initialize the cell's value to 0

            rowCells.push_back(cell); // Add the cell to the current row
        }

        grid.push_back(rowCells); // Add the completed row to the grid
    }
}

// Draw method
// Renders the grid and displays cell values (if non-zero) on the specified SFML window
void GridHandler::draw(sf::RenderWindow& window) const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            window.draw(cell.shape); // Draw the cell

            // Draw the cell's value as text if it's greater than 0
            if (cell.value > 0) {
                sf::Font font;
                if (font.loadFromFile("arial.ttf")) { // Load font for displaying text
                    sf::Text text(std::to_string(cell.value), font, 24); // Create text with cell value
                    text.setPosition(
                        cell.shape.getPosition().x + cell.shape.getSize().x / 4,
                        cell.shape.getPosition().y + cell.shape.getSize().y / 4
                    );
                    text.setFillColor(sf::Color::Black); // Set text color
                    window.draw(text); // Draw the text
                }
            }
        }
    }
}

// placeValue method
// Attempts to place a value in the specified column
// Returns true if successful, false if the column is full or invalid
bool GridHandler::placeValue(int column, int value) {
    if (column < 0 || column >= cols) {
        return false; // Check for invalid column
    }

    // Start from the bottom row and move upward
    for (int row = rows - 1; row >= 0; --row) {
        if (grid[row][column].value == 0) { // Find the first empty cell in the column
            grid[row][column].value = value; // Set the cell's value
            return true; // Indicate success
        }
    }
    return false; // Column is full
}

// getColumnValue method
// Returns the value of the first non-zero cell in the specified column
// Returns -1 if the column is invalid or 0 if the column is empty
int GridHandler::getColumnValue(int column) const {
    if (column < 0 || column >= cols) {
        return -1; // Check for invalid column
    }

    // Iterate over rows from top to bottom
    for (int row = 0; row < rows; ++row) {
        if (grid[row][column].value != 0) {
            return grid[row][column].value; // Return the first non-zero value
        }
    }
    return 0; // Column is empty
}
