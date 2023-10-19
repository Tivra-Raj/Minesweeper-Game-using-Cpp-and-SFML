#include "Constants.cpp"
using namespace std;
using namespace sf;

class Tile
{
	//Tile
	Texture tileTexture;
	Sprite Tile_Sprite;
	Texture openTileTexture;
	Sprite Open_Tile_Sprite;

	//Mine
	Texture mineTexture;
	Sprite Mine_Sprite;

	//flag
	Texture flagTexture;
	Sprite Flag_Sprite;

	//numbers
	Texture numbersTexture;
	Sprite Numbers_Sprite;

	//bool variables
	bool is_mine;
	bool is_open;
	bool is_flagged;
	bool is_clicked;

	//variables
	int mine_around;

public:


	// Constructor to Initialize
	Tile()
	{
		// VARIABLES
		is_mine = false;
		is_open = false;
		is_flagged = false;
		is_clicked = false;
		mine_around = 0;

		// Loading Textures
		tileTexture.loadFromFile(TILE_SPRITE_PATH);
		openTileTexture.loadFromFile(OPEN_TILE_SPRITE_PATH);
		numbersTexture.loadFromFile(NUMBERS_SPRITE_PATH);
		mineTexture.loadFromFile(MINE_SPRITE_PATH);
		flagTexture.loadFromFile(FLAG_SPRITE_PATH);

		// Making Sprites
		Tile_Sprite.setTexture(tileTexture);
		Open_Tile_Sprite.setTexture(openTileTexture);
		Numbers_Sprite.setTexture(numbersTexture);
		Mine_Sprite.setTexture(mineTexture);
		Flag_Sprite.setTexture(flagTexture);

		// Resize Sprites
		Vector2f targetSize(SPRITE_SIZE, SPRITE_SIZE);
		Flag_Sprite.setScale(targetSize.x / Flag_Sprite.getLocalBounds().width, targetSize.y / Flag_Sprite.getLocalBounds().height);
		Mine_Sprite.setScale(targetSize.x / Mine_Sprite.getLocalBounds().width, targetSize.y / Mine_Sprite.getLocalBounds().height);
		Tile_Sprite.setScale(targetSize.x / Tile_Sprite.getLocalBounds().width, targetSize.y / Tile_Sprite.getLocalBounds().height);
		Open_Tile_Sprite.setScale(targetSize.x / Open_Tile_Sprite.getLocalBounds().width, targetSize.y / Open_Tile_Sprite.getLocalBounds().height);
	}

	bool get_isMine()
	{
		return is_mine;
	}

	void set_Mine(bool value)
	{
		is_mine = value;
	}

	int get_MineAround()
	{
		return mine_around;
	}

	void set_MineAround(int count)
	{
		mine_around = count;
	}

	bool get_isOpen()
	{
		return is_open;
	}

	void set_isOpen(bool value)
	{
		is_open = value;
	}

	bool get_isFlagged()
	{
		return is_flagged;
	}

	void set_isFlagged(bool value)
	{
		is_flagged = value;
	}

	// DrawTile
	void DrawTile(RenderWindow& window, GameStatus gameStatus)
	{
		window.draw(Tile_Sprite);
	}

	// DrawTile with 0 number
	void DrawOpenTile(RenderWindow& window, GameStatus gameStatus)
	{
		window.draw(Open_Tile_Sprite);
	}

	// DrawMine
	void DrawMine(RenderWindow& window, GameStatus gameStatus)
	{
		window.draw(Mine_Sprite);
	}

	// Draw Numbers from 1 to 8
	void DrawNumbers(RenderWindow& window, GameStatus gameStatus)
	{
		if (mine_around > 0)
		{
			// Calculate the texture coordinates for the number
			int textureWidth = numbersTexture.getSize().x;
			int textureHeight = numbersTexture.getSize().y;
			int spriteWidth = textureWidth / 8;  // Assuming you have 8 numbers in a row

			int number = mine_around;
			int rectLeft = (number - 1) * spriteWidth;
			int rectTop = 0;

			// Set the texture rectangle
			Numbers_Sprite.setTextureRect(IntRect(rectLeft, rectTop, spriteWidth, textureHeight));

			// Scale the sprite to fit the cell size
			float scaleX = static_cast<float>(CELL_SIZE) / spriteWidth;
			float scaleY = static_cast<float>(CELL_SIZE) / textureHeight;
			Numbers_Sprite.setScale(scaleX, scaleY);

			// Position the sprite in the center of the tile
			float posX = Tile_Sprite.getPosition().x + (CELL_SIZE - Numbers_Sprite.getGlobalBounds().width) / 2;
			float posY = Tile_Sprite.getPosition().y + (CELL_SIZE - Numbers_Sprite.getGlobalBounds().height) / 2;
			Numbers_Sprite.setPosition(posX, posY);

			// Draw the sprite
			window.draw(Numbers_Sprite);
		}
	}

	void DrawFlag(RenderWindow& window, GameStatus gameStatus)
	{
		window.draw(Flag_Sprite);
	}

	// Sets Tile, Flag, Mine Sprite Positions.
	void SetTilePosition(float tilePos_x, float tilePos_y)
	{
		Flag_Sprite.setPosition(Vector2f(tilePos_x, tilePos_y));
		Mine_Sprite.setPosition(Vector2f(tilePos_x, tilePos_y));
		Tile_Sprite.setPosition(Vector2f(tilePos_x, tilePos_y));
		Open_Tile_Sprite.setPosition(Vector2f(tilePos_x, tilePos_y));
	}
};