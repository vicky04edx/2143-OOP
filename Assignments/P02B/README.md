## P02B - Class Design 
### Victoria Heredia
### Description:

This assignment requires designing a set of classes for a digital version of the game "Knucklebones" using object-oriented principles, focusing on inheritance and composition. The goal is to outline each class's attributes and methods, define relationships between the components, and categorize features as necessary, possible, or wishful for the game.

### Class Design Outline

### Dice Class
#### Data (Attributes):

`sides`: Number of sides on the dice (default: 6).

`current_value`: Value of the dice after rolling.

#### Actions (Methods):

`roll()`: Simulates rolling the dice and assigns a random value between 1 and 6 to current_value.

`get_value()`: Returns the current value of the dice.

#### Relationships:

A Player HAS-A set of Dice (composition).
Dice is used during the game for rolling and placing.

### Player Class
#### Data (Attributes):

`name`: Player’s name.

`score`: The current score of the player.

`grid[3][3]`: 3x3 grid where the player places dice.

`dice_set`: A set of dice used by the player for rolling.

`player_stats`: Could include stats such as wins, losses, and high score.

#### Actions (Methods):

`roll_dice()`: Rolls a dice and returns the rolled value.

`place_dice(int column, int value)`: Places a dice in the selected column of the grid.

`get_score()`: Calculates and returns the current score based on grid contents and scoring rules.

`update_score()`: Updates the player's score after placing dice.

`remove_opponent_dice()`: Removes opponent's matching dice if placed in the same column.

#### Relationships:

A Player HAS-A set of Dice (composition).
A Player IS-A participant in the game (composition with Game).
