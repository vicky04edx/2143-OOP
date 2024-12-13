#include "player.hpp"

// Constructor
// Initializes the Player object with the given name
Player::Player(const std::string& name) : name(name) {}

// Getter for the player's name
// Returns the player's name as a constant reference
const std::string& Player::getName() const {
    return name;
}
