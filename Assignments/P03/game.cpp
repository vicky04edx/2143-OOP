// #include <SFML/Graphics.hpp> 
// #include <SFML/System.hpp>
// #include <vector>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <SFML/Window.hpp>
// #include "button_class.hpp"
// #include "grid_class.hpp"
// #include "nameinput_class.hpp"
// #include "player.hpp"
// #include "GridHandler.hpp"

// int main() {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Knucklebones");

//     // Load textures for dice animation frames (frame1.png to frame6.png)
//     std::vector<sf::Texture> textures;
//     for (int i = 1; i <= 6; ++i) {
//         sf::Texture texture;
//         if (!texture.loadFromFile("frame" + std::to_string(i) + ".png")) {
//             std::cerr << "Error loading frame" << i << ".png" << std::endl;
//             return -1;
//         }
//         textures.push_back(texture);
//     }

//     // Create sprite for dice animation
//     sf::Sprite diceSprite;
//     diceSprite.setTexture(textures[0]);
//     diceSprite.setPosition(100.f, 200.f);

//     // Timing variables for animation
//     sf::Clock clock;
//     const sf::Time frameDuration = sf::milliseconds(200);
//     size_t currentFrame = 0;
//     bool isRolling = false; // To track if the dice is rolling

//     // Initialize buttons
//     Button rollButton(sf::Vector2f(120, 50), sf::Vector2f(100.f, 500.f), sf::Color::Green, "Roll");
//     Button stopButton(sf::Vector2f(120, 50), sf::Vector2f(250.f, 500.f), sf::Color::Red, "Stop");

//     // Initialize grid
//     Grid grid(3, 3, 100.f, 10.f, 400.f, 100.f);

//     // Initialize name input
//     NameInput nameInput;

//     // Initialize player
//     Player player("");

//     // Random seed for dice rolls
//     std::srand(static_cast<unsigned int>(std::time(nullptr)));

//     // Load font for the start text
//     sf::Font font;
//     if (!font.loadFromFile("arial.ttf")) {
//         std::cerr << "Error loading font\n";
//         return -1;
//     }

//     // Create the "Press Enter to Start" text
//     sf::Text startText("Press Enter to Start", font, 30);
//     startText.setPosition(250.f, 250.f);
//     startText.setFillColor(sf::Color::Blue);

//     bool isInNameInput = true;

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }

//             // Wait for Enter key to continue to name input
//             if (isInNameInput && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
//                 isInNameInput = false; // Proceed to name input
//             }

//             // Handle name input
//             if (isInNameInput) {
//                 nameInput.handleInput(event);
//             }

//             if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                 if (rollButton.isClicked(sf::Mouse::getPosition(window))) {
//                     isRolling = true;
//                     clock.restart();
//                 }
//                 if (stopButton.isClicked(sf::Mouse::getPosition(window))) {
//                     isRolling = false;
//                 }
//             }
//         }

//         // Update dice animation frame if rolling
//         if (isRolling) {
//             if (clock.getElapsedTime() >= frameDuration) {
//                 currentFrame = (currentFrame + 1) % textures.size();
//                 diceSprite.setTexture(textures[currentFrame]);
//                 clock.restart();
//             }
//         }

//         // Clear window and draw components
//         window.clear(sf::Color::White);

//         // Display "Press Enter to Start" text when waiting for the user to press Enter
//         if (isInNameInput) {
//             window.draw(startText); // Draw the "Press Enter to Start" text
//             nameInput.draw(window); // Draw the name input box
//         } else {
//             // Draw game elements after name input is done
//             rollButton.draw(window);
//             stopButton.draw(window);
//             grid.draw(window);
//             window.draw(diceSprite);
//         }

//         window.display();
//     }
//     return 0;
// }
/////////////////////////////////////////////////////////////

// #include <SFML/Graphics.hpp> 
// #include <SFML/System.hpp>
// #include <vector>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <SFML/Window.hpp>
// #include "button_class.hpp"
// #include "grid_class.hpp"
// #include "nameinput_class.hpp"
// #include "player.hpp"
// #include "GridHandler.hpp"

// int main() {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Knucklebones");

//     // Load textures for dice animation frames (frame1.png to frame6.png)
//     std::vector<sf::Texture> textures;
//     for (int i = 1; i <= 6; ++i) {
//         sf::Texture texture;
//         if (!texture.loadFromFile("frame" + std::to_string(i) + ".png")) {
//             std::cerr << "Error loading frame" << i << ".png" << std::endl;
//             return -1;
//         }
//         textures.push_back(texture);
//     }

//     // Create sprite for dice animation
//     sf::Sprite diceSprite;
//     diceSprite.setTexture(textures[0]);
//     diceSprite.setPosition(100.f, 200.f);

//     // Timing variables for animation
//     sf::Clock clock;
//     const sf::Time frameDuration = sf::milliseconds(200);
//     size_t currentFrame = 0;
//     bool isRolling = false; // To track if the dice is rolling

//     // Initialize buttons
//     Button rollButton(sf::Vector2f(120, 50), sf::Vector2f(100.f, 500.f), sf::Color::Green, "Roll");
//     Button stopButton(sf::Vector2f(120, 50), sf::Vector2f(250.f, 500.f), sf::Color::Red, "Stop");

//     // Initialize GridHandler
//     GridHandler gridHandler(400.f, 100.f, 3, 3, 100.f, 10.f);

//     // Initialize name input
//     NameInput nameInput;

//     // Initialize player
//     Player player("");

//     // Random seed for dice rolls
//     std::srand(static_cast<unsigned int>(std::time(nullptr)));

//     // Load font for the start text
//     sf::Font font;
//     if (!font.loadFromFile("arial.ttf")) {
//         std::cerr << "Error loading font\n";
//         return -1;
//     }

//     // Create the "Press Enter to Start" text
//     sf::Text startText("Press Enter to Start", font, 30);
//     startText.setPosition(250.f, 250.f);
//     startText.setFillColor(sf::Color::Blue);

//     bool isInNameInput = true;

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }

//             // Wait for Enter key to continue to name input
//             if (isInNameInput && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
//                 isInNameInput = false; // Proceed to name input
//             }

//             // Handle name input
//             if (isInNameInput) {
//                 nameInput.handleInput(event);
//             }

//             if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                 if (rollButton.isClicked(sf::Mouse::getPosition(window))) {
//                     isRolling = true;
//                     clock.restart();
//                 }
//                 if (stopButton.isClicked(sf::Mouse::getPosition(window))) {
//                     isRolling = false;

//                     // Stop rolling and place dice value
//                     int rollResult = (std::rand() % 6) + 1;
//                     sf::Vector2i mousePos = sf::Mouse::getPosition(window);

//                     for (int col = 0; col < 3; ++col) {
//                         if (gridHandler.placeValue(col, rollResult)) {
//                             break;
//                         }
//                     }
//                 }
//             }
//         }

//         // Update dice animation frame if rolling
//         if (isRolling) {
//             if (clock.getElapsedTime() >= frameDuration) {
//                 currentFrame = (currentFrame + 1) % textures.size();
//                 diceSprite.setTexture(textures[currentFrame]);
//                 clock.restart();
//             }
//         }

//         // Clear window and draw components
//         window.clear(sf::Color::White);

//         // Display "Press Enter to Start" text when waiting for the user to press Enter
//         if (isInNameInput) {
//             window.draw(startText); // Draw the "Press Enter to Start" text
//             nameInput.draw(window); // Draw the name input box
//         } else {
//             // Draw game elements after name input is done
//             rollButton.draw(window);
//             stopButton.draw(window);
//             gridHandler.draw(window);
//             window.draw(diceSprite);
//         }

//         window.display();
//     }

//     return 0;
// }
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Window.hpp>
#include "button_class.hpp"
#include "grid_class.hpp"
#include "nameinput_class.hpp"
#include "player.hpp"
#include "GridHandler.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Knucklebones");

    // Load textures for dice animation frames (frame1.png to frame6.png)
    std::vector<sf::Texture> textures;
    for (int i = 1; i <= 6; ++i) {
        sf::Texture texture;
        if (!texture.loadFromFile("frame" + std::to_string(i) + ".png")) {
            std::cerr << "Error loading frame" << i << ".png" << std::endl;
            return -1;
        }
        textures.push_back(texture);
    }

    // Create sprite for dice animation
    sf::Sprite diceSprite;
    diceSprite.setTexture(textures[0]);
    diceSprite.setPosition(100.f, 200.f);

    // Timing variables for animation
    sf::Clock clock;
    const sf::Time frameDuration = sf::milliseconds(200);
    size_t currentFrame = 0;
    bool isRolling = false; // To track if the dice is rolling
    int rollResult = 0; // To store the roll result

    // Initialize buttons
    Button rollButton(sf::Vector2f(120, 50), sf::Vector2f(100.f, 500.f), sf::Color::Green, "Roll");
    Button stopButton(sf::Vector2f(120, 50), sf::Vector2f(250.f, 500.f), sf::Color::Red, "Stop");

    // Initialize GridHandler
    GridHandler gridHandler(400.f, 100.f, 3, 3, 100.f, 10.f);

    // Initialize name input
    NameInput nameInput;

    // Initialize player
    Player player("");

    // Random seed for dice rolls
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Load font for the start text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Create the "Press Enter to Start" text
    sf::Text startText("Press Enter to Start", font, 30);
    startText.setPosition(250.f, 250.f);
    startText.setFillColor(sf::Color::Blue);

    bool isInNameInput = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Wait for Enter key to continue to name input
            if (isInNameInput && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                isInNameInput = false; // Proceed to name input
            }

            // Handle name input
            if (isInNameInput) {
                nameInput.handleInput(event);
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // Handle roll button click
                if (rollButton.isClicked(sf::Mouse::getPosition(window))) {
                    isRolling = true;
                    clock.restart();
                }

                // Handle stop button click (only stops animation)
                if (stopButton.isClicked(sf::Mouse::getPosition(window))) {
                    isRolling = false;

                    // Stop rolling and set the roll result to match the animation
                    rollResult = (std::rand() % 6) + 1;
                    diceSprite.setTexture(textures[rollResult - 1]); // Set texture based on roll result
                }

                // Handle placing the dice result on the grid when clicked
                if (!isRolling && rollResult > 0) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    for (int col = 0; col < 3; ++col) {
                        if (gridHandler.placeValue(col, rollResult)) {
                            break;
                        }
                    }
                    rollResult = 0; // Reset roll result after placing it
                }
            }
        }

        // Update dice animation frame if rolling
        if (isRolling) {
            if (clock.getElapsedTime() >= frameDuration) {
                currentFrame = (currentFrame + 1) % textures.size();
                diceSprite.setTexture(textures[currentFrame]);
                clock.restart();
            }
        }

        // Clear window and draw components
        window.clear(sf::Color::White);

        // Display "Press Enter to Start" text when waiting for the user to press Enter
        if (isInNameInput) {
            window.draw(startText); // Draw the "Press Enter to Start" text
            nameInput.draw(window); // Draw the name input box
        } else {
            // Draw game elements after name input is done
            rollButton.draw(window);
            stopButton.draw(window);
            gridHandler.draw(window);
            window.draw(diceSprite);
        }

        window.display();
    }

    return 0;
}
