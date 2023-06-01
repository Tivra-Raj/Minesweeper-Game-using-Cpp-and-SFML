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
#define UIBG_SPRITE_POSX 1300
#define UIBG_SPRITE_POSY 250

//Font
#define BUTTON_FONT "Assets/Fonts/AmberyGardenRegular-PKjGd.ttf"
#define BUTTON_TEXT_SIZE 50
#define BUTTON_TEXT_COLOR Color::White

//UI Button
#define UI_BUTTON_SPRITE_PATH "Assets/Sprites/UIbutton.png"
#define UI_BUTTON_WIDTH 1.3f
#define UI_BUTTON_HEIGHT 1.5f

//UI Button Hovered
#define UI_BUTTON_HOVERED_WIDTH 1.4f
#define UI_BUTTON_HOVERED_HEIGHT 1.6f

//Restart Button
#define RESTART_BUTTON_POSX 1410
#define RESTART_BUTTON_POSY 550
#define RESTART_BUTTON_TEXT "RESTART"
#define RESTART_TEXT_POS Vector2f(1485, 563)

//Quit Button
#define QUIT_BUTTON_POSX 1410
#define QUIT_BUTTON_POSY 700
#define QUIT_BUTTON_TEXT "QUIT"
#define QUIT_TEXT_POS Vector2f(1525, 713)

//Flag Button
#define DEFAULT " "
#define FLAG_SPRITE_POSX 1470
#define FLAG_SPRITE_POSY 425
#define FLAG_TEXT_STRING " : 40 / 40"
#define FLAG_TEXT_COLOR Color::Red
#define FLAG_TEXT_POS Vector2f(1530, 425)

//Status UI
#define STATUS_FONT_PATH "Assets/Fonts/Aloevera-OVoWO.ttf"
#define STATUS_FONT_SIZE 75
#define STATUS_TEXT_POS Vector2f(1350, 140)
#define COMPLETE_STATUS "YOU WON !!"
#define FAILED_STATUS "GAME OVER"
#define STATUS_PROGRESS_COLOR Color::Black
#define STATUS_COMPLETE_COLOR Color::Green
#define STATUS_FAILED_COLOR Color::Red

//Emoji -> can't forget him
#define INPROGRESS_EMOJI_SPRITE_PATH "Assets/Sprites/Inprogress.png"
#define GAMEWON_EMOJI_SPRITE_PATH "Assets/Sprites/GameWon.png"
#define GAMEOVER_EMOJI_SPRITE_PATH "Assets/Sprites/GameOver.png"
#define EMOJI_SPRITE_POSX 1540
#define EMOJI_SPRITE_POSY 315

// Game Status Based on Progress
enum GameStatus
{
	Game_Win,
	Game_Over,
	InProgress
};