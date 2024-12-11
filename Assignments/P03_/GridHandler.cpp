#include "GridHandler.hpp"

GridHandler::GridHandler(float startX, float startY, int rows, int cols, float cellSize, float cellSpacing)
    : rows(rows), cols(cols) {
    for (int row = 0; row < rows; ++row) {
        std::vector<Cell> rowCells;
        for (int col = 0; col < cols; ++col) {
            Cell cell;
            cell.shape.setSize(sf::Vector2f(cellSize, cellSize));
            cell.shape.setPosition(startX + col * (cellSize + cellSpacing), startY + row * (cellSize + cellSpacing));
            cell.shape.setFillColor(sf::Color::White);
            cell.shape.setOutlineColor(sf::Color::Black);
            cell.shape.setOutlineThickness(2.f);
            cell.value = 0;
            rowCells.push_back(cell);
        }
        grid.push_back(rowCells);
    }
}

void GridHandler::draw(sf::RenderWindow& window) const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            window.draw(cell.shape);
            if (cell.value > 0) {
                sf::Font font;
                if (font.loadFromFile("arial.ttf")) {
                    sf::Text text(std::to_string(cell.value), font, 24);
                    text.setPosition(
                        cell.shape.getPosition().x + cell.shape.getSize().x / 4,
                        cell.shape.getPosition().y + cell.shape.getSize().y / 4
                    );
                    text.setFillColor(sf::Color::Black);
                    window.draw(text);
                }
            }
        }
    }
}

bool GridHandler::placeValue(int column, int value) {
    if (column < 0 || column >= cols) {
        return false; // Invalid column
    }
    for (int row = rows - 1; row >= 0; --row) {
        if (grid[row][column].value == 0) {
            grid[row][column].value = value;
            return true;
        }
    }
    return false; // Column is full
}

int GridHandler::getColumnValue(int column) const {
    if (column < 0 || column >= cols) {
        return -1; // Invalid column
    }
    for (int row = 0; row < rows; ++row) {
        if (grid[row][column].value != 0) {
            return grid[row][column].value;
        }
    }
    return 0; // Column is empty
}
