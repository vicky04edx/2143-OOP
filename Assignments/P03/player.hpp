#ifndef PLAYER_HPP  // Check if PLAYER_HPP has not been defined
#define PLAYER_HPP  // Define PLAYER_HPP to prevent multiple inclusions of this header file

#include <string>  // Include the string header to use std::string

// Player class declaration
class Player {
public:
    // Constructor to initialize a Player object with a name
    Player(const std::string& name);  

    // Getter function to retrieve the player's name
    const std::string& getName() const; 

private:
    std::string name;  // Member variable to store the player's name
};

#endif // PLAYER_HPP  // End of the header guard