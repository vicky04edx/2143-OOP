#include <locale.h>
#include <ncurses.h>

#include "button_class.hpp"
#include "color_class.hpp"
#include "dice_class.hpp"
#include "grid_class.hpp"
#include "input_class.hpp"
#include "logger_class.hpp"
#include <ctime>
#include <string>
#include <vector>
#include <cstring> // change: included this library

using namespace std;

class Player
{
    string name;
    int score;
  public:
    void setName(string n){name = n;}
    void printName(){Logger::log("Name",name);}
};


// class Game {
// public:
//     Game();

//     // Main gameplay methods
//     void start();
//     void take_turn();
//     bool check_win() const;

//     // Game setup and utility methods
//     void initialize_players(const std::string& player1_name, const std::string& player2_name);
//     void roll_dice();

//     // UI methods with ncurses for display
//     void display_game_state();
//     void end_game();

// private:
//     DiceViz dice;
//     Grid grids[2];               // Two-player grid system
//     Player* current_player;
//     Player players[2];

//     void switch_turn();
// };


int main() {
    srand(time(0));
    setlocale(LC_ALL, "");  // Enable Unicode support
    initscr();
    cbreak();
    noecho();
    curs_set(0);  // Hide the cursor
    clear();
    refresh();


    // Create an Input object with a prompt
    Input inputBox("Enter your name: ", 3, 60, 5, 10);

    // Display the input box
    inputBox.printBorder();

    // Capture the user's input
    inputBox.captureInput();

    // Retrieve the input string
    std::string playerName = inputBox.getInput();

    // Clear the window and print a welcome message
    clear();
    mvprintw(8, 5, "Welcome, %s! Press 'q' to quit.", playerName.c_str());
    refresh();

    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    start_color();

    colorful();

    Logger::setFilePath("log.txt");



    int rows, cols, size;
    int ch;

    getmaxyx(stdscr, rows, cols);

    string text = "ROLL";

    size = strlen(text.c_str()) + 2;

    Logger::log("vals", vector<int>({size, 3, (rows / 2), ((cols - size) / 2)}));

    // Button button(text, 2, 1, Frame({size, 3, (rows / 2), ((cols - size) / 2)}));
    Button button(text, 5, 32, Frame({3, size, 10, 15}));
    button.draw_button();

    Grid grid(1, 10);
    grid.refreshGrid();

    DiceViz dice(3, 30);

    dice.setBorderColor(11);
    dice.setDotColor(5);

    while (true) {
        if (ch == 'q' || ch == 'Q') {
            break;
        } else if (ch == KEY_MOUSE) {
            MEVENT event;
            Logger::log("Mouse pressed", "true");
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {
                    Logger::log("clicked", vector<int>({event.y, event.x}));
                    if (button.clicked(event.y, event.x)) {
                        button.draw_button();
                         Logger::log("drawing button", "true");
                        dice.animate_dice(30);
                        dice.draw_dice(dice.getLastDiceValue());
                        button.toggle();
                        
                    }
                    if (grid.clicked(event.y, event.x - 1)) {
                        Logger::log("clicked grid", "true");
                        dice.clear();
                        grid.addValue(event.y, event.x - 1, dice.getLastDiceValue());  // Mark click location
                        grid.refreshGrid();
                    }
                }
            }
        }
        Logger::log("Key pressed", to_string(ch));
        button.draw_button();
        refresh();
        ch = getch();
    }

    clear();
    endwin();
    return 0;
}