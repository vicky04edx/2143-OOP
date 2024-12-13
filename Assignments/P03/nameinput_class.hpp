#ifndef NAMEINPUT_CLASS_HPP
#define NAMEINPUT_CLASS_HPP

#include <SFML/Graphics.hpp>
#include <string>

// The NameInput class handles user input for entering a name
// It displays a prompt and dynamically updates the player's name as they type
class NameInput {
public:
    // Constructor
    // Initializes the font, prompt text, and player name display
    NameInput();

    // Draw method
    // Renders the prompt and the current player name on the provided SFML window
    void draw(sf::RenderWindow& window) const;

    // Handles keyboard input events for entering or modifying the player's name
    void handleInput(sf::Event event);

    // Getter for the player's name
    // Returns the name entered by the player as a constant reference
    const std::string& getPlayerName() const;

private:
    // Stores the player's name input
    std::string playerName;

    // SFML Text object for the prompt ("Enter your name:")
    sf::Text nameText;

    // SFML Text object for displaying the player's input
    sf::Text playerNameText;

    // Font used for both the prompt and player name text
    sf::Font font;
};

#endif // NAMEINPUT_CLASS_HPP