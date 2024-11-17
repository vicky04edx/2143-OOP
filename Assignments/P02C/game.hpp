// Game.hpp

#include <string>
#include <iostream>

class Game {
public:
    Game();

    // Main gameplay methods
    void start();
    void take_turn();
    bool check_win() const;

    // Game setup and utility methods
    void initialize_players();
    void roll_dice();

    // Optional UI methods
    void display_game_state();
    void end_game();

private:
    DiceViz dice;
    Grid grids[2];               // Two-player grid system
    Player* current_player;
    Player players[2];

    void switch_turn();
};
