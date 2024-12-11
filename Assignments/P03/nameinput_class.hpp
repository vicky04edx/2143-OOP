#ifndef NAMEINPUT_CLASS_HPP
#define NAMEINPUT_CLASS_HPP

#include <SFML/Graphics.hpp>
#include <string>

class NameInput {
public:
    NameInput();

    void draw(sf::RenderWindow& window) const;
    void handleInput(sf::Event event);
    const std::string& getPlayerName() const;

private:
    std::string playerName;
    sf::Text nameText;
    sf::Text playerNameText;
    sf::Font font;
};

#endif // NAMEINPUT_CLASS_HPP

