#include <SFML/Graphics.hpp>
using namespace sf;

#define TITLE "MineSweeper C++ & SFML"

//Screen Size
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define VERTICAL_OFFSET 100.0f
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
#define MINE_COUNT 40

//UI

//UI Background
#define UIBG_SPRITE_PATH "Assets/Sprites/UIbg.png"
#define UIBG_SPRITE_POSX 1250
#define UIBG_SPRITE_POSY 370

//Font
#define BUTTON_FONT "Assets/Fonts/AmberyGardenRegular-PKjGd.ttf"
#define BUTTON_TEXT_SIZE 50
#define BUTTON_TEXT_COLOR Color::White

//Game Title
#define GAME_TITLE_FONT_PATH "Assets/Fonts/Aloevera-OVoWO.ttf"
#define GAME_TITLE_FONT_SIZE 76
#define GAME_TITLE_TEXT_POS Vector2f(1090, 40)
#define GAME_TITLE_TEXT "MINESWEEPER GAME"
#define GAME_TITLE_COLOR Color::Blue

//Creator Name
#define CREATOR_NAME_FONT_PATH "Assets/Fonts/Aloevera-OVoWO.ttf"
#define CREATOR_NAME_FONT_SIZE 40
#define CREATOR_NAME_TEXT_POS Vector2f(1300, 130)
#define CREATOR_NAME_TEXT "Created By Tivra Raj"
#define CREATOR_NAME_COLOR Color::White

//UI Button
#define UI_BUTTON_SPRITE_PATH "Assets/Sprites/UIbutton.png"
#define UI_BUTTON_WIDTH 1.3f
#define UI_BUTTON_HEIGHT 1.5f

//UI Button Hovered
#define UI_BUTTON_HOVERED_WIDTH 1.4f
#define UI_BUTTON_HOVERED_HEIGHT 1.6f

//Restart Button
#define RESTART_BUTTON_POSX 1360
#define RESTART_BUTTON_POSY 700
#define RESTART_BUTTON_TEXT "RESTART"
#define RESTART_TEXT_POS Vector2f(1435, 713)

//Quit Button
#define QUIT_BUTTON_POSX 1360
#define QUIT_BUTTON_POSY 850
#define QUIT_BUTTON_TEXT "QUIT"
#define QUIT_TEXT_POS Vector2f(1475, 863)

//Flag Button
#define DEFAULT " "
#define FLAG_SPRITE_POSX 1385
#define FLAG_SPRITE_POSY 555
#define FLAG_TEXT_STRING " : 40 / 40"
#define FLAG_TEXT_COLOR Color::Red
#define FLAG_TEXT_POS Vector2f(1445, 555)

//Status UI
#define STATUS_FONT_PATH "Assets/Fonts/Aloevera-OVoWO.ttf"
#define STATUS_FONT_SIZE 65
#define STATUS_TEXT_POS Vector2f(1300, 270)
#define COMPLETE_STATUS "YOU WON !!"
#define FAILED_STATUS "GAME OVER"
#define STATUS_PROGRESS_COLOR Color::Black
#define STATUS_COMPLETE_COLOR Color::Green
#define STATUS_FAILED_COLOR Color::Red

//Emoji -> can't forget him
#define INPROGRESS_EMOJI_SPRITE_PATH "Assets/Sprites/Inprogress.png"
#define GAMEWON_EMOJI_SPRITE_PATH "Assets/Sprites/GameWon.png"
#define GAMEOVER_EMOJI_SPRITE_PATH "Assets/Sprites/GameOver.png"
#define EMOJI_SPRITE_POSX 1490
#define EMOJI_SPRITE_POSY 445

// Game Status Based on Progress
enum GameStatus
{
	Game_Win,
	Game_Over,
	InProgress
};