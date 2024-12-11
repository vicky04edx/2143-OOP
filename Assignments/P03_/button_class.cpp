// #include "button_class.hpp"
// #include <SFML/Graphics.hpp>
// #include <iostream>

// Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& label) {
//     buttonShape.setSize(size);
//     buttonShape.setPosition(position);
//     buttonShape.setFillColor(color);

//     if (!font.loadFromFile("arial.ttf")) {
//         std::cerr << "Error loading font\n";
//     }

//     buttonLabel.setFont(font);
//     buttonLabel.setString(label);
//     buttonLabel.setCharacterSize(20);
//     buttonLabel.setFillColor(sf::Color::White);
//     buttonLabel.setPosition(position.x + (size.x / 4), position.y + (size.y / 4));
// }

// void Button::draw(sf::RenderWindow& window) const {
//     window.draw(buttonShape);
//     window.draw(buttonLabel);
// }

// bool Button::isClicked(sf::Vector2i mousePos) const {
//     return buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
// }

// void Button::setLabel(const std::string& label) {
//     buttonLabel.setString(label);
// }
// button_class.cpp
#include "button_class.hpp"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text) {
    buttonShape.setSize(size);
    buttonShape.setPosition(position);
    buttonShape.setFillColor(color);

    if (!font.loadFromFile("arial.ttf")) {
        // Handle error
    }
    
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(position.x + (size.x - buttonText.getLocalBounds().width) / 2, position.y + (size.y - buttonText.getLocalBounds().height) / 2);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const sf::Vector2i& mousePosition) {
    return buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}