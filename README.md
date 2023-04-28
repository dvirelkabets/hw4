# Card Game

This project is a multiplayer card game in which players aim to win battles and reach level 10. The game reads the card deck from a file and gets players via input. In each round, each player draws one card in turn from the deck of cards and plays the card. The drawn card can benefit the player by increasing their life points, amount of coins, and levels, or harm them by damaging their life points and even resetting them so that the player loses and leaves the game.

## Requirements
- C++11 or higher
- An input file containing a list of card names

## Installation
To install this game, you need to have C++11 or higher installed on your system.

1. Download or clone the source code from the repository.
2. Compile the code using a C++ compiler.
3. Run the game.

## Usage
To start the game, run the compiled executable. The game will read the card deck from the file specified by the user and ask the number of players who want to participate. After that, each player needs to provide their name and select the type of character they want to play.

During each round, every player draws a card from the deck and plays it. A player can win the game by reaching level 10 or lose the game by reaching 0 life points. The game continues without a player until either a player reaches level 10 or their life points reach zero.
