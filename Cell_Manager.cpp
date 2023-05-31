#include <iostream>
#include <random>
#include <queue>
#include "Tile.cpp"
using namespace std;
using namespace sf;

class Grid
{
	Tile grid[ROWS][COLS];

	bool first_click;

	int flagCount;

public:

	// Constructor for Initializing and setting Tile Position.
	Grid()
	{
		ResetGrid();
	}

	// Reset Grid whenever you want to play Again.
	void ResetGrid()
	{
		first_click = false;
		flagCount = MINE_COUNT;

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				grid[i][j].SetTilePosition(VERTICAL_OFFSET + CELL_SIZE * i, HORIZONTAL_OFFSET + CELL_SIZE * j);
				grid[i][j].set_Mine(false);
				grid[i][j].set_isOpen(false);
				grid[i][j].set_isFlagged(false);
			}
		}
	}

	// Check if Row & Col are valid in Grid.
	bool isValidTileGrid(int row, int col)
	{
		if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
		{
			return true;
		}
		return false;
	}

	bool CheckGameWin()
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				// Check if a non-mine cell is not open
				if (!grid[i][j].get_isMine() && !grid[i][j].get_isOpen())
				{
					return false;
				}
			}
		}

		// All non-mine cells are open, game is won
		return true;
	}


	void SetMine(int clickedRow, int clickedCol)
	{
		default_random_engine random_engine(random_device{}());

		uniform_int_distribution<int> x_distribution(0, COLS - 1);
		uniform_int_distribution<int> y_distribution(0, ROWS - 1);

		first_click = true;
		int count = 0;

		while (count < MINE_COUNT)
		{
			int mine_x = x_distribution(random_engine);
			int mine_y = y_distribution(random_engine);

			if (!grid[mine_x][mine_y].get_isMine() && (mine_x != clickedRow || mine_y != clickedCol))
			{
				grid[mine_x][mine_y].set_Mine(true);
				count++;
			}
		}
	}

	void OpenAdjacentMineAround(int x, int y, GameStatus& gameStatus)
	{
		if (isValidTileGrid(x, y) && !grid[x][y].get_isOpen() && !grid[x][y].get_isFlagged())
		{
			grid[x][y].set_isOpen(true);

			if (grid[x][y].get_isFlagged())
			{
				// Remove the flag from the cell
				grid[x][y].set_isFlagged(false);
				flagCount++; // Increment the flag count
				return;
			}

			if (grid[x][y].get_isMine())
			{
				// Game over, handle mine explosion
				gameStatus = GameStatus::Game_Over;
				cout << "Game Over!" << endl;
			}
			else
			{
				// Check if the cell is flagged and doesn't contain a mine
				if (grid[x][y].get_isFlagged() && grid[x][y].get_MineAround() == 0)
				{
					// Remove the flag
					grid[x][y].set_isFlagged(false);
					// Increment the flag count
					flagCount++;
				}

				int countMineAround = countAdjacentMinesAround(x, y);
				grid[x][y].set_MineAround(countMineAround);

				if (countMineAround == 0)
				{
					// Open adjacent cells recursively if there are no adjacent mines
					queue<pair<int, int>> cellQueue;
					cellQueue.push(make_pair(x, y));

					while (!cellQueue.empty())
					{
						pair<int, int> currentCell = cellQueue.front();

						if (grid[x][y].get_isFlagged())
						{
							// Remove the flag from the cell
							grid[x][y].set_isFlagged(false);
							flagCount++; // Increment the flag count
						}
						cellQueue.pop();

						int currentX = currentCell.first;
						int currentY = currentCell.second;

						// Check and open neighboring cells
						for (int i = currentX - 1; i <= currentX + 1; i++)
						{
							for (int j = currentY - 1; j <= currentY + 1; j++)
							{
								if (isValidTileGrid(i, j) && !grid[i][j].get_isOpen())
								{
									grid[i][j].set_isOpen(true);

									int adjMineCount = countAdjacentMinesAround(i, j);
									grid[i][j].set_MineAround(adjMineCount);

									bool isAlreadyNotClicked = !grid[i][j].get_isMine();
									if (isAlreadyNotClicked)
									{
										grid[i][j].set_isOpen(true);
										if (grid[i][j].get_isFlagged())
										{
											// Remove the flag from the cell
											grid[i][j].set_isFlagged(false);
											flagCount++; // Increment the flag count
										}
									}

									// If the adjacent cell has no adjacent mines, enqueue it for processing
									if (adjMineCount == 0)
									{
										cellQueue.push(make_pair(i, j));
									}
								}
							}
						}
					}
				}
			}
		}
	}



	int countAdjacentMinesAround(int x, int y)
	{
		int mine_Around = 0;

		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (isValidTileGrid(i, j) && grid[i][j].get_isMine())
				{
					mine_Around++;
				}
			}
		}

		return mine_Around;
	}

	void open_cell(Vector2i mouse_pos, GameStatus& gameStatus)
	{
		if (gameStatus != GameStatus::InProgress)
			return;

		float pos_x = mouse_pos.x;
		float pos_y = mouse_pos.y;

		if (pos_x < VERTICAL_OFFSET || pos_y < HORIZONTAL_OFFSET || pos_x >= VERTICAL_OFFSET + CELL_SIZE * ROWS || pos_y >= HORIZONTAL_OFFSET + CELL_SIZE * COLS)
			return;

		// Convert the pixel coordinates to grid indices
		int gridPos_row = (int)((pos_x - VERTICAL_OFFSET) / CELL_SIZE) % ROWS;
		int gridPos_col = (int)((pos_y - HORIZONTAL_OFFSET) / CELL_SIZE) % COLS;

		// VALID INPUT - CHECK FOR CLICKCOUNT
		if (!first_click)
		{
			SetMine(gridPos_row, gridPos_col);
			first_click = true;
		}

		OpenAdjacentMineAround(gridPos_row, gridPos_col, gameStatus);

		if (CheckGameWin() && !GameStatus::Game_Win)
		{
			gameStatus = GameStatus::Game_Win;
			cout << "You Win!" << endl;
		}
	}

	// No. of flags placed.
	int getFlagCount()
	{
		return flagCount;
	}

	void PlaceFlag(Vector2i mouse_pos)
	{
		// Convert the pixel coordinates to grid indices
		float pos_x = mouse_pos.x;
		float pos_y = mouse_pos.y;

		if (pos_x < VERTICAL_OFFSET || pos_y < HORIZONTAL_OFFSET || pos_x >= VERTICAL_OFFSET + CELL_SIZE * ROWS || pos_y >= HORIZONTAL_OFFSET + CELL_SIZE * COLS)
			return;


		// Convert the pixel coordinates to grid indices
		int gridPos_row = (int)((pos_x - VERTICAL_OFFSET) / CELL_SIZE) % ROWS;
		int gridPos_col = (int)((pos_y - HORIZONTAL_OFFSET) / CELL_SIZE) % COLS;

		if (isValidTileGrid(gridPos_row, gridPos_col) && !grid[gridPos_row][gridPos_col].get_isOpen())
		{
			bool currentFlagState = grid[gridPos_row][gridPos_col].get_isFlagged();

			// Check if the maximum number of flags has been reached and the current cell is not already flagged
			if (!currentFlagState && flagCount == 0)
			{
				// Maximum flags reached, cannot place more flags
				return;
			}

			// Check if the current cell is already flagged
			if (currentFlagState)
			{
				// Flag removed from the cell, so increment the flag count
				flagCount++;
			}
			else
			{
				// Check if the flag count is greater than zero before placing a flag
				if (flagCount > 0)
				{
					// Flag placed on the cell, so decrement the flag count
					flagCount--;
				}
				else
				{
					// No flags available to place, return
					return;
				}
			}

			// Update the flagged state of the cell
			grid[gridPos_row][gridPos_col].set_isFlagged(!currentFlagState);
		}
	}


	// Draw Grid on window.
	void DrawGrid(RenderWindow& window, GameStatus gameStatus)
	{
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++)
			{
				if (grid[i][j].get_isOpen())
				{
					if (grid[i][j].get_isMine())
					{
						grid[i][j].DrawMine(window, gameStatus);
					}
					else
					{
						if (grid[i][j].get_MineAround() > 0)
						{
							grid[i][j].DrawNumbers(window, gameStatus);
						}
						else
						{
							grid[i][j].DrawOpenTile(window, gameStatus);
						}
					}
				}
				else
				{
					if (grid[i][j].get_isFlagged() && !grid[i][j].get_isOpen())
					{
						grid[i][j].DrawFlag(window, gameStatus);
					}
					else
					{
						grid[i][j].DrawTile(window, gameStatus);
					}
				}

			}
		}
	}
};