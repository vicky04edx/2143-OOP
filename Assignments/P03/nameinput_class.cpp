#include "nameinput_class.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor for NameInput
// Initializes font, sets up text objects for prompt and player name input
NameInput::NameInput() {
    // Load font from file, log an error if loading fails
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

    // Configure the prompt text to ask for the player's name
    nameText.setFont(font);
    nameText.setString("Enter your name: ");
    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::Black);
    nameText.setPosition(250.f, 300.f);

    // Configure the text object to display the player's input
    playerNameText.setFont(font);
    playerNameText.setCharacterSize(20);
    playerNameText.setFillColor(sf::Color::Black);
    playerNameText.setPosition(250.f, 330.f);
}

// Draw method
// Renders the prompt and player input text to the SFML window
void NameInput::draw(sf::RenderWindow& window) const {
    window.draw(nameText);
    window.draw(playerNameText);
}

// Handles player input events for entering their name
void NameInput::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        // If backspace is pressed and the player's name is not empty, remove the last character
        if (event.text.unicode == 8 && !playerName.empty()) { 
            playerName.pop_back();
        }
        // If the input character is valid (ASCII range), append it to the player's name
        else if (event.text.unicode < 128) { 
            playerName += static_cast<char>(event.text.unicode);
        }
        // Update the displayed player name with the current input
        playerNameText.setString(playerName);
    }
}

// Getter for the player's name
// Returns a constant reference to the player's name string
const std::string& NameInput::getPlayerName() const {
    return playerName;
}