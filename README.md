# Minesweeper-Game-using-Cpp-and-SFML By Tivra Raj

- Minesweeper is a logic puzzle video game genre. The game features a grid of clickable squares, with hidden "mines" scattered throughout the board. The objective is to clear the board without detonating any mines, with help from clues about the number of neighboring mines in each field. 
- In the game, mines are scattered throughout a board, which is divided into cells. 
- Cells have three states: unopened, opened, and flagged. 
- An unopened cell is blank and clickable, while an opened cell is exposed. 
- Flagged cells are unopened cells marked by the player to indicate a potential mine location.

---

# How to play

- A player selects a cell to open it. 
- If a player opens a mined cell, the game ends in a loss. Otherwise, the opened cell displays either a number, indicating the number of mines diagonally and/or adjacent to it, or a blank tile (or "0"), and all adjacent non-mined cells will automatically be opened. 
- Players can also flag a cell, visualised by a flag being put on the location, to denote that they believe a mine to be in that place. 
- Flagged cells are considered unopened, and if player found that mine is not possible in that cell then he/she can unflagged also.
- If Non-mine cell is flagged and if player trigger a jackpot by opening large number of cells then those placed flag will get removed automatically.

---

# My work

- I use C++ for the logical part like opening of cell, placement of mine, counting adjacent mines, gameplay status.
- While I use SFML (Simple & fast multimedia language) for my graphical representation of my game like drawing tile, mine, UI etc.<br>(don't want to use boring text based representation) <img src="https://github.com/Tivra-Raj/Minesweeper-Game-using-Cpp-and-SFML/assets/107213542/55bc1a72-61cd-4ee2-84c4-d2069d071987" alt="face-with-tongue" width="25" />

---

# Small video of gameplay showing my game
