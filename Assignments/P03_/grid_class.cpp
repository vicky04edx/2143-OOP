#include "grid_class.hpp"

Grid::Grid(int rows, int cols, float cellSize, float cellSpacing, float startX, float startY)
    : rows(rows), cols(cols), cellSize(cellSize), cellSpacing(cellSpacing), startX(startX), startY(startY), columnValues(cols, 0) {

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setFillColor(sf::Color::White);
            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(2.f);
            cell.setPosition(startX + col * (cellSize + cellSpacing), startY + row * (cellSize + cellSpacing));
            gridCells.push_back(cell);
        }
    }
}

void Grid::draw(sf::RenderWindow& window) const {
    for (const auto& cell : gridCells) {
        window.draw(cell);
    }
}

void Grid::update(int col, int value) {
    columnValues[col] = value;
}

const std::vector<int>& Grid::getColumnValues() const {
    return columnValues;
}


