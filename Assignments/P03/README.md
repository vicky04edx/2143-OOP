## P03 - Knuckle Bones using SFML
### Victoria Heredia
### Description:

This project simulates a digital version of the game "Knucklebones" using SFML (Simple and Fast Multimedia Library) for graphics and interactivity. The program incorporates various classes to handle the grid, buttons, players, and game logic while providing a polished visual and interactive experience. The implementation demonstrates object-oriented programming principles and creative use of SFML features.


### Files

|   #   | File             | Description                                        |
| :---: | ---------------- | -------------------------------------------------- |
|   1   | [game.cpp](./game.cpp)   | The main file, coordinating the game loop and class interactions. |
|   2   | [GridHandler.hpp](./GridHandler.hpp) | Manages the game grid, including dice rolls and grid updates.|
|   3   | [GridHandler.cpp](./GridHandler.cpp) | Implements the functionality of the game grid. |
|   4   | [button_class.hpp](./button_class.hpp)   | Defines buttons for user interactions, such as rolling dice. |
|   5   | [button_class.cpp](./button_class.cpp)   | Implements button functionality and rendering.|
|   6   | [nameinput_class.hpp](./nameinput_class.hpp)   | Handles text input for player names.|
|   7   | [nameinput_class.cpp](./nameinput_class.cpp)   | 
Implements the text input handling.|
|   8   | [grid_class.hpp](./grid_class.hpp)   | Defines the structure and operations of the game grid. |
|   9   | [grid_class.cpp](./grid_class.cpp)   | Implements the game grid's logic and visualization. |
|   10   | [player.hpp](./player.hpp)   | Defines player properties, such as score and name.|
|   11   | [player.cpp](./player.cpp)   | Implements player-related functionalities. |
|   12  | [sfml_build.sh](./sfml_build.sh)   | A script to build the project with SFML. |
|   13  | [arial.ttf](./arial.ttf)   | Font file for text rendering. |
|   14  | [frame1.png](./frame1.png)   | Visual asset for animation or game interface. |
|   15  | [frame2.png](./frame2.png)   | Visual asset for animation or game interface. |
|   16  | [frame3.png](./frame3.png)   | Visual asset for animation or game interface. |
|   17  | [frame4.png](./frame4.png)   | Visual asset for animation or game interface. |
|   18  | [frame5.png](./frame5.png)   | Visual asset for animation or game interface. |
|   19  | [frame6.png](./frame6.png)   | Visual asset for animation or game interface. |


## Instructions

1. Set Up the Environment:

- Ensure SFML is installed on your system.

- Place all required files (e.g., .cpp, .hpp, images, and fonts) in the same directory. 

2. Compile the code using `g++` with the ncurses library.
    
    `g++ game.cpp grid_class.cpp player.cpp button_class.cpp nameinput_class.cpp GridHandler.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system` 

3. Execute the compiled program.
    
    `./game`  

4. Interact with the Game: Use buttons and inputs displayed on the screen to play the game. Follow on-screen prompts to proceed.

### Pending Features:

- Finalize game rules for rolling dice, scoring, and updating grids.

- Add multiplayer mode to allow more than one player to participate.

- Implement for and score updates.

### Challenges Encountered:
- Dynamic Input Handling: Handling simultaneous inputs without conflicts.

- Font Rendering: Ensuring text is legible at various screen sizes and resolutions.

### Next Steps:

- Optimize grid and button interactions for smooth gameplay.

- Make the grid handle user input (mouse click) to put the correspondent numebers in the grid after rolling the dice.

### Screenshots:

<img src=sfml_hw.png width=300>               <img src=sfml_hw1.png width=300>

<img src=sfml_hw2.png width=300>              <img src=sfml_hw3.png width=300>
