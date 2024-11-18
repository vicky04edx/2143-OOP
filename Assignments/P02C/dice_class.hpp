// #pragma once
// // #include <locale.h>
// #include <ncurses.h>
// #include <unistd.h>  // For usleep()

// #include "logger_class.hpp"
// #include <map>
// #include <string>
// #include <utility>

// using namespace std;

// class DiceViz {
//     WINDOW *win;
//     int border_color;
//     int dot_color;
//     int x;
//     int y;
//     std::map<std::string, std::pair<int, int> > dot_pos;
//     int last_dice_value;

//    public:
//     DiceViz(int y, int x) : y(y), x(x) {
//         win             = newwin(5, 7, y, x);
//         border_color    = 1;
//         dot_color       = 1;
//         last_dice_value = 0;
//         // Add entries to the map
//         dot_pos["ul"] = std::make_pair(1, 1);  // Upper left
//         dot_pos["ur"] = std::make_pair(1, 5);  // Upper right
//         dot_pos["ml"] = std::make_pair(2, 1);  // Middle left
//         dot_pos["mm"] = std::make_pair(2, 3);  // Middle middle
//         dot_pos["mr"] = std::make_pair(2, 5);  // Middle right
//         dot_pos["ll"] = std::make_pair(3, 1);  // Lower left
//         dot_pos["lr"] = std::make_pair(3, 5);  // Lower right
//     }

//     void setBorderColor(int bcolor) { border_color = bcolor; }
//     void setDotColor(int dcolor) { dot_color = dcolor; }

//     void draw_dice(int number) {
//         // Draw the box around the dice

//         wattron(win, COLOR_PAIR(border_color));  // Turn on color pair 2
//         box(win, 0, 0);
//         wattroff(win, COLOR_PAIR(border_color));  // Turn off the color

//         wrefresh(win);

//         wattron(win, COLOR_PAIR(dot_color));  // Turn on color pair 2

//         // Print dots based on the number on the dice
//         switch (number) {
//             case 1:
//                 mvwprintw(win, dot_pos["mm"].first, dot_pos["mm"].second, "●");
//                 break;
//             case 2:
//                 mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "●");
//                 mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "●");
//                 break;
//             case 3:
//                 mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "●");
//                 mvwprintw(win, dot_pos["mm"].first, dot_pos["mm"].second, "●");
//                 mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "●");
//                 break;
//             case 4:
//                 mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "●");
//                 mvwprintw(win, dot_pos["ur"].first, dot_pos["ur"].second, "●");
//                 mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "●");
//                 mvwprintw(win, dot_pos["ll"].first, dot_pos["ll"].second, "●");
//                 break;
//             case 5:
//                 mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "●");
//                 mvwprintw(win, dot_pos["ur"].first, dot_pos["ur"].second, "●");
//                 mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "●");
//                 mvwprintw(win, dot_pos["ll"].first, dot_pos["ll"].second, "●");
//                 mvwprintw(win, dot_pos["mm"].first, dot_pos["mm"].second, "●");
//                 break;
//             case 6:
//                 mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "●");
//                 mvwprintw(win, dot_pos["ur"].first, dot_pos["ur"].second, "●");
//                 mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "●");
//                 mvwprintw(win, dot_pos["ll"].first, dot_pos["ll"].second, "●");
//                 mvwprintw(win, dot_pos["ml"].first, dot_pos["ml"].second, "●");
//                 mvwprintw(win, dot_pos["mr"].first, dot_pos["mr"].second, "●");
//                 break;
//         }
//         wattroff(win, COLOR_PAIR(dot_color));  // Turn off the color
//         wrefresh(win);
//         // delwin(win);
//     }

//     void refresh() { wrefresh(win); }
//     void clear() { wclear(win); }
//     int getLastDiceValue() { return last_dice_value; }

//     void animate_dice(int refresh_count, int sleep_amnt = 100000) {
//         // Shuffle dice faces for a set amount of time
//         for (int i = 0; i < refresh_count; ++i) {
//             last_dice_value = (rand() % 6 + 1);  // Random number between 1 and 6
//             // No need to clear the whole screen, just refresh the dice window
//             draw_dice(last_dice_value);
//             Logger::log("Dice Value", to_string(last_dice_value));
//             Logger::printLastLine(stdscr);
//             usleep(sleep_amnt);  // 100ms delay for visual effect
//             clear();
//         }
//     }
// };
#pragma once
#include <ncurses.h>
#include <unistd.h>  // For usleep()
#include <map>
#include <string>
#include <utility>

using namespace std;

class DiceViz {
    WINDOW *win; // Window pointer for dice display
    int border_color;
    int dot_color;
    int x, y;
    std::map<std::string, std::pair<int, int>> dot_pos;
    int last_dice_value;

public:
    DiceViz(int y, int x) : y(y), x(x), last_dice_value(0), border_color(1), dot_color(1) {
        win = newwin(5, 7, y, x); // Create a window for the dice

        // Define positions for dice dots
        dot_pos["ul"] = std::make_pair(1, 1); // Upper left
        dot_pos["ur"] = std::make_pair(1, 5); // Upper right
        dot_pos["ml"] = std::make_pair(2, 1); // Middle left
        dot_pos["mm"] = std::make_pair(2, 3); // Center
        dot_pos["mr"] = std::make_pair(2, 5); // Middle right
        dot_pos["ll"] = std::make_pair(3, 1); // Lower left
        dot_pos["lr"] = std::make_pair(3, 5); // Lower right
    }

    void setBorderColor(int bcolor) { border_color = bcolor; }
    void setDotColor(int dcolor) { dot_color = dcolor; }

   void draw_dice(int number) {
    // Draw the box around the dice

        wattron(win, COLOR_PAIR(border_color));  // Turn on color pair 2
        box(win, 0, 0);
        wattroff(win, COLOR_PAIR(border_color));  // Turn off the color

        wrefresh(win);

        wattron(win, COLOR_PAIR(dot_color));  // Turn on color pair 2

        // Print dots based on the number on the dice
        switch (number) {
            case 1:
                mvwprintw(win, dot_pos["mm"].first, dot_pos["mm"].second, "*");
                break;
            case 2:
                mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "*");
                mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "*");
                break;
            case 3:
                mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "*");
                mvwprintw(win, dot_pos["mm"].first, dot_pos["mm"].second, "*");
                mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "*");
                break;
            case 4:
                mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "*");
                mvwprintw(win, dot_pos["ur"].first, dot_pos["ur"].second, "*");
                mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "*");
                mvwprintw(win, dot_pos["ll"].first, dot_pos["ll"].second, "*");
                break;
            case 5:
                mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "*");
                mvwprintw(win, dot_pos["ur"].first, dot_pos["ur"].second, "*");
                mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "*");
                mvwprintw(win, dot_pos["ll"].first, dot_pos["ll"].second, "*");
                mvwprintw(win, dot_pos["mm"].first, dot_pos["mm"].second, "*");
                break;
            case 6:
                mvwprintw(win, dot_pos["ul"].first, dot_pos["ul"].second, "*");
                mvwprintw(win, dot_pos["ur"].first, dot_pos["ur"].second, "*");
                mvwprintw(win, dot_pos["lr"].first, dot_pos["lr"].second, "*");
                mvwprintw(win, dot_pos["ll"].first, dot_pos["ll"].second, "*");
                mvwprintw(win, dot_pos["ml"].first, dot_pos["ml"].second, "*");
                mvwprintw(win, dot_pos["mr"].first, dot_pos["mr"].second, "*");
                break;
        }
        wattroff(win, COLOR_PAIR(dot_color));
        wrefresh(win);
    }

    void refresh() { wrefresh(win); }
    void clearDice() { werase(win); box(win, 0, 0); wrefresh(win); }
    int getLastDiceValue() { return last_dice_value; }

    void animate_dice(int refresh_count, int sleep_amnt = 100000) {
    for (int i = 0; i < refresh_count; ++i) {
        last_dice_value = (rand() % 6) + 1; // Random number between 1 and 6
        
        // Draw the dice with the current value
        draw_dice(last_dice_value);

        // Display the current dice value on the game screen
        //mvprintw(0, 0, "Rolling... Current dice value: %d", last_dice_value);
        refresh(); // Refresh the screen to show updates

        // Delay for visual effect
        usleep(sleep_amnt);

        // Clear the dice display
        clearDice();
    }
    
    // Final output after the animation ends
    mvprintw(1, 0, "Dice value: %d", last_dice_value);
    refresh(); // Ensure final value is displayed
}


    ~DiceViz() {
        delwin(win); // Clean up the window
    }
};

