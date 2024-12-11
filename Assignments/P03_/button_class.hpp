// #ifndef BUTTON_CLASS_HPP
// #define BUTTON_CLASS_HPP

// #include <SFML/Graphics.hpp>

// class Button {
// public:
//     Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& label);

//     void draw(sf::RenderWindow& window) const;
//     bool isClicked(sf::Vector2i mousePos) const;
//     void setLabel(const std::string& label);

// private:
//     sf::RectangleShape buttonShape;
//     sf::Text buttonLabel;
//     sf::Font font;
// };

// #endif // BUTTON_CLASS_HPP
// button_class.hpp
#ifndef BUTTON_CLASS_HPP
#define BUTTON_CLASS_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePosition);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
};

#endif