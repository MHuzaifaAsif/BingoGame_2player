# Bingo Game

## Description

This Bingo Game is a two-player console-based game coded by **Error 404**. The game allows two players to play Bingo on randomly generated 5x5 cards. The players take turns calling out numbers between 1 and 25. The first player to complete a row, column, or diagonal with zeros wins the game.

## Features

- **Two-player game**: Two players can participate and enter their names.
- **Randomly generated Bingo cards**: Each player gets a 5x5 Bingo card with random numbers between 1 and 25.
- **Toss for player turn**: A toss determines who goes first.
- **Number calling**: Players enter numbers between 1 and 25 to cross off their Bingo cards.
- **Game history**: The results of each game are saved in a file for later review.
- **Instructions**: Clear instructions are provided for the gameplay.
- **Credits**: Acknowledgements for the algorithm and logic used in the game.

## Game Flow

1. **Main Menu**: The game starts by presenting a menu with the following options:
   - Instructions
   - Play the Game
   - Credits
   - Game History
   - Exit

2. **Gameplay**:
   - Players take turns entering a number between 1 and 25.
   - If the number is present on the Bingo card, it is replaced by a `0`.
   - The first player to have five `0`s in a row, column, or diagonal wins.

3. **Winning Condition**: The game checks for five consecutive `0`s in any row, column, or diagonal for each player. Once a player wins, their name is displayed as the winner.

4. **Game History**: After each game, the results are saved to a file named `Game History.txt`, including the winner and game ID.

## Instructions

To start the game, select option `2` in the main menu. Then, enter your name and your opponent’s name. The game will generate a random Bingo card for each player, and you’ll take turns calling out numbers between 1 and 25. The first player to complete a row, column, or diagonal wins.

## Installation

1. Clone or download this repository to your local machine.
2. Compile the C++ program using a C++ compiler.
3. Run the program in a console or terminal.

## Usage

1. Choose an option from the main menu:
   - `1`: View instructions.
   - `2`: Start playing the game.
   - `3`: View credits.
   - `4`: View the game history.
   - `5`: Exit the game.
   
2. When playing, enter a number between 1 and 25 to mark your Bingo card.

## Files

- `main.cpp`: The main source code for the Bingo game.
- `Game History.txt`: A text file that stores the history of each game, including the winner and game ID.

## License

This project is open-source and free to use. You can modify and distribute the code as per your requirements.

## Credits

- **Algorithm and flowchart**: Rafay
- **Logic and checks**: Rafay
- **Game coding**: Rafay
