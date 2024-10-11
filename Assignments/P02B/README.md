## P02B - Class Design 
### Victoria Heredia
### Description:

This assignment requires designing a set of classes for a digital version of the game "Knucklebones" using object-oriented principles, focusing on inheritance and composition. The goal is to outline each class's attributes and methods, define relationships between the components, and categorize features as necessary, possible, or wishful for the game.

### Class Design Outline

### Dice Class
#### - Data (Attributes):

`sides`: Number of sides on the dice (default: 6).

`current_value`: Value of the dice after rolling.

#### - Actions (Methods):

`roll()`: Simulates rolling the dice and assigns a random value between 1 and 6 to current_value.

`get_value()`: Returns the current value of the dice.

#### - Relationships:

A Player HAS-A set of Dice (composition).
Dice is used during the game for rolling and placing.

### Player Class
#### - Data (Attributes):

`name`: Player’s name.

`score`: The current score of the player.

`grid[3][3]`: 3x3 grid where the player places dice.

`dice_set`: A set of dice used by the player for rolling.

`player_stats`: Could include stats such as wins, losses, and high score.

#### - Actions (Methods):

`roll_dice()`: Rolls a dice and returns the rolled value.

`place_dice(int column, int value)`: Places a dice in the selected column of the grid.

`get_score()`: Calculates and returns the current score based on grid contents and scoring rules.

`update_score()`: Updates the player's score after placing dice.

`remove_opponent_dice()`: Removes opponent's matching dice if placed in the same column.

#### - Relationships:

A Player HAS-A set of Dice (composition).
A Player IS-A participant in the game (composition with Game).

### Game Class
#### - Data (Attributes):
`vector<Player> players`: A dynamic array of players participating in the game.

`map<string, int> scores`: Maps player IDs (or names) to their scores.

`bool isDone`: Tracks if the game has ended.

#### - Actions (Methods):

`addToScore(string uid, int val)`: Adds val to the player's score using their unique ID.

`start_game()`: Starts the game and initializes players.

`end_game()`: Ends the game and checks for the winner.

`get_winner()`: Determines the player with the highest score.

#### - Relationships:
A Game HAS-A collection of players stored in a vector<Player>.
A Game uses a map to manage player scores dynamically.

### Knucklebones Class (inherits from Game)
#### - Data (Attributes):
`board`: A 3x3 grid specific to Knucklebones.

`knucklebones_specific_rules`: Specific rules for Knucklebones, including multipliers and dice removal.

#### - Actions (Methods):
`start_round()`: Starts a round of Knucklebones.

`end_round()`: Ends the current round and checks if the game should finish.

`calculate_winner()`: Determines the winner by comparing player scores.

#### - Relationships:
Knucklebones IS-A Game (inheritance).

### Keywords Classification:
#### - Necessary:
First name, Score, Player stats, Winner

#### - Possible:
High score, Leaderboard, Streak

#### - Wishful: 
Chat, Coins, Levels, Messaging, Teams, Team stats, Userid

### Inheritance vs. Composition:
#### - Inheritance:
The Knucklebones class inherits from the Game class because Knucklebones IS-A Game.

#### - Composition:
The Player class has a HAS-A relationship with Dice because a player HAS-A set of dice.
The Game class has a HAS-A relationship with Player because a game HAS-A set of players.
