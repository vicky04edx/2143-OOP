## P02C - Knuckle Bones
### Victoria Heredia
### Description:

This program simulates a digital version of the game "Knucklebones" using ncurses for the interface. Players interact with the game through various classes such as Grid, Button, Logger, and Input. The project is a work in progress, focusing on setting up the game logic and user interaction.


### Files

|   #   | File             | Description                                        |
| :---: | ---------------- | -------------------------------------------------- |
|   1   | [game.cpp](./game.cpp)   | The main file, coordinating the overall game flow and class interactions.  |
|   2   | [grid_class.hpp](./grid_class.hpp) | Handles the game grid where dice rolls and game logic are visualized. |
|   3   | [button_class.hpp](./button_class.hpp) | Defines interactive buttons for user inputs (e.g., rolling dice).  |
|   4   | [input_class.hpp](./input_class.hpp)   | Manages text input boxes for player interactions, such as entering a name. |
|   5   | [logger_class.hpp](./logger_class.hpp)   | Logs game events or messages to the console. |
|   6   | [color_class.hpp](./color_class.hpp)   | Provides color customization for the game interface. |


## Instructions

1. Use the `cd` command to change to the directory containing `game.cpp` and the necessary header files.
    
    Example:
    vh@VickysLaptop:~$ cd ~/projects/2143-OOP/Assignments/P02C  

2. Compile the code using `g++` with the ncurses library.
    
    g++ -std=c++20 game.cpp -o main -l ncurses 

3. Execute the compiled program.
    
    ./main  

4. Upon running the program, an input box will prompt you to enter the player's name. Enter your name and press `Enter` to continue.

## Work in Progress 
### Pending Features:

- Complete game logic for rolling dice, updating grids, and calculating scores.

- Displaying real-time score updates.

- Implementing multiplayer functionality.

### Challenges Encountered:

- Overlapping Text: The input box sometimes overlaps the prompt and previously printed messages.

- Input Box Placement: Adjusting the position of the input box dynamically without conflicts.

- Color Configurations: Consistent color application for borders and text across the interface.

### Next Steps:

- Fix text and box alignment issues to ensure a clean display.

- Integrate the player name with other game components (e.g., score tracking).

- Test for edge cases and enhance error handling in the input process.