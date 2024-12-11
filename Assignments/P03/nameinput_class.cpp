#include "nameinput_class.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

NameInput::NameInput() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

      
    nameText.setFont(font);
    nameText.setString("Enter your name: ");
    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::Black);
    nameText.setPosition(250.f, 300.f);

    playerNameText.setFont(font);
    playerNameText.setCharacterSize(20);
    playerNameText.setFillColor(sf::Color::Black);
    playerNameText.setPosition(250.f, 330.f);
}

void NameInput::draw(sf::RenderWindow& window) const {
    window.draw(nameText);
    window.draw(playerNameText);
}

void NameInput::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 8 && !playerName.empty()) { // Backspace
            playerName.pop_back();
        } else if (event.text.unicode < 128) { // Acceptable input
            playerName += static_cast<char>(event.text.unicode);
        }
        playerNameText.setString(playerName);
    }
}

const std::string& NameInput::getPlayerName() const {
    return playerName;
}
