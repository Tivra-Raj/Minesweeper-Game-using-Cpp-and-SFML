#include <SFML/Graphics.hpp>
using namespace sf;

#define TITLE "MineSweeper C++ & SFML"

//Screen Size
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define VERTICAL_OFFSET 140.0f
#define HORIZONTAL_OFFSET 70.0f

//Cell
#define CELL_SIZE 60
#define ROWS 16
#define COLS 16

//Sprite size
#define SPRITE_SIZE 60

//Sprite path
#define TILE_SPRITE_PATH "Assets/Sprites/tile.png"
#define OPEN_TILE_SPRITE_PATH "Assets/Sprites/opentile.png"
#define MINE_SPRITE_PATH "Assets/Sprites/mine.png"
#define FLAG_SPRITE_PATH "Assets/Sprites/flag.png"
#define NUMBERS_SPRITE_PATH "Assets/Sprites/numbers.png"

//Mine
#define MINE_COUNT 2

//UI

//UI Background
#define UIBG_SPRITE_PATH "Assets/Sprites/UIbg.png"
#define UIBG_SPRITE_POSX 1400
#define UIBG_SPRITE_POSY 200

//Font
#define BUTTON_FONT "Assets/Fonts/Antonio-Regular.ttf"
#define BUTTON_TEXT_SIZE 50
#define BUTTON_TEXT_COLOR Color::Black

//UI Button
#define UI_BUTTON_SPRITE_PATH "Assets/Sprites/UIbutton.png"
#define UI_BUTTON_WIDTH 300
#define UI_BUTTON_HEIGHT 100
#define BUTTON_COLOR Color{200, 200, 255}
#define BUTTON_HOVER_COLOR sf::Color{150, 150, 255}

//Restart Button
#define RESTART_BUTTON_POSX 1525
#define RESTART_BUTTON_POSY 500
#define RESTART_BUTTON_TEXT "RESTART"
#define RESTART_TEXT_POS Vector2f(1600, 525)

//Quit Button
#define QUIT_BUTTON_POSX 1525
#define QUIT_BUTTON_POSY 700
#define QUIT_BUTTON_TEXT "QUIT"
#define QUIT_TEXT_POS Vector2f(1625, 725)

//Flag Button
#define DEFAULT " "
#define FLAG_BUTTON_POSX 1525
#define FLAG_BUTTON_POSY 300
#define FLAG_SPRITE_POSX 1575
#define FLAG_SPRITE_POSY 325
#define FLAG_TEXT_STRING " : 40 / 40"
#define FLAG_TEXT_COLOR Color::White
#define FLAG_TEXT_POS Vector2f(1625, 325)

//Status UI
#define STATUS_FONT_PATH "Assets/Fonts/Mitr-Regular.ttf"
#define STATUS_FONT_SIZE 75
#define STATUS_TEXT_POS Vector2f(1475, 125)
#define COMPLETE_STATUS "YOU WIN !!"
#define FAILED_STATUS "GAME OVER"
#define STATUS_PROGRESS_COLOR Color::Black
#define STATUS_COMPLETE_COLOR Color::Green
#define STATUS_FAILED_COLOR Color::Red

// Game Status Based on Progress
enum GameStatus
{
	Game_Win,
	Game_Over,
	InProgress
};