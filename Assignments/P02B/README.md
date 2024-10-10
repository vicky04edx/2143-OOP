## P02B - Class Design 
### Victoria Heredia
### Description:

This assignment requires designing a set of classes for a digital version of the game "Knucklebones" using object-oriented principles, focusing on inheritance and composition. The goal is to outline each class's attributes and methods, define relationships between the components, and categorize features as necessary, possible, or wishful for the game.

### Class Design Outline

## Dice Class
# Data (Attributes):

`sides`: Number of sides on the dice (default: 6).
`current_value`: Value of the dice after rolling.

# Actions (Methods):

`roll()`: Simulates rolling the dice and assigns a random value between 1 and 6 to current_value.
`get_value()`: Returns the current value of the dice.

# Relationships:

A Player HAS-A set of Dice (composition).
Dice is used during the game for rolling and placing.






