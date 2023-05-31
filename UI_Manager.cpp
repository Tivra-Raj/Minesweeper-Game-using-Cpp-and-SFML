#include <SFML/Graphics.hpp>
#include "Cell_Manager.cpp"

class UIManager
{
	Texture UIBgTexture;
	Sprite UI_BG_Sprite;

	Text statusText;
	Font statusFont;
	Texture flagTexture;
	Sprite Flag_Sprite;
	RectangleShape FlagButton;
	Text FlagText;
	RectangleShape RestartButton;
	Text RestartText;
	RectangleShape QuitButton;
	Text QuitText;
	Font font;

public:
	// Constructor To Initialize All Elements.
	UIManager()
	{
		Vector2f targetSize(SPRITE_SIZE, SPRITE_SIZE);

		//font
		font.loadFromFile(BUTTON_FONT);

		//UI
		UIBgTexture.loadFromFile(UIBG_SPRITE_PATH);
		UI_BG_Sprite.setTexture(UIBgTexture);
		UI_BG_Sprite.setScale(1.0f, 3.0f);
		UI_BG_Sprite.setPosition(UIBG_SPRITE_POSX, UIBG_SPRITE_POSY);

		//Restart Button
		RestartButton = RectangleShape(Vector2f(UI_BUTTON_WIDTH, UI_BUTTON_HEIGHT));
		RestartButton.setPosition(RESTART_BUTTON_POSX, RESTART_BUTTON_POSY);
		RestartButton.setFillColor(BUTTON_COLOR);

		//Restart Text
		RestartText.setFont(font);
		RestartText.setFillColor(BUTTON_TEXT_COLOR);
		RestartText.setCharacterSize(BUTTON_TEXT_SIZE);
		RestartText.setString(RESTART_BUTTON_TEXT);
		RestartText.setPosition(RESTART_TEXT_POS);

		// QUIT BUTTON
		QuitButton = RectangleShape(Vector2f(UI_BUTTON_WIDTH, UI_BUTTON_HEIGHT));
		QuitButton.setPosition(QUIT_BUTTON_POSX, QUIT_BUTTON_POSY);
		QuitButton.setFillColor(BUTTON_COLOR);

		// QUIT TEXT
		QuitText.setFont(font);
		QuitText.setFillColor(BUTTON_TEXT_COLOR);
		QuitText.setCharacterSize(BUTTON_TEXT_SIZE);
		QuitText.setString(QUIT_BUTTON_TEXT);
		QuitText.setPosition(QUIT_TEXT_POS);

		//Flag Textures & Sprites
		flagTexture.loadFromFile(FLAG_SPRITE_PATH);
		Flag_Sprite.setTexture(flagTexture);
		Flag_Sprite.setScale(targetSize.x / Flag_Sprite.getLocalBounds().width, targetSize.y / Flag_Sprite.getLocalBounds().height);
		Flag_Sprite.setPosition(FLAG_SPRITE_POSX, FLAG_SPRITE_POSY);

		// FLAG TEXT
		FlagText.setFont(font);
		FlagText.setFillColor(FLAG_TEXT_COLOR);
		FlagText.setCharacterSize(BUTTON_TEXT_SIZE);
		FlagText.setString(FLAG_TEXT_STRING);
		FlagText.setPosition(FLAG_TEXT_POS);

		// GAME STATUS TEXT
		statusFont.loadFromFile(STATUS_FONT_PATH);
		statusText.setFont(statusFont);
		statusText.setFillColor(STATUS_PROGRESS_COLOR);
		statusText.setCharacterSize(STATUS_FONT_SIZE);
		statusText.setString(DEFAULT);
		statusText.setPosition(STATUS_TEXT_POS);
	}

	// Checks & Updates Restart & Quit Buttons on Hover. Also returns true if hovering.
	pair<bool, bool> UpdateButtonOnHover(Vector2i mouse_pos) {
		float pos_x = mouse_pos.x;
		float pos_y = mouse_pos.y;
		if (pos_x > RESTART_BUTTON_POSX && pos_x < RESTART_BUTTON_POSX + UI_BUTTON_WIDTH && pos_y > RESTART_BUTTON_POSY && pos_y < RESTART_BUTTON_POSY + UI_BUTTON_HEIGHT) {
			RestartButton.setFillColor(BUTTON_HOVER_COLOR);
			return { true, false };
		}
		else if (pos_x > QUIT_BUTTON_POSX && pos_x < QUIT_BUTTON_POSX + UI_BUTTON_WIDTH && pos_y > QUIT_BUTTON_POSY && pos_y < QUIT_BUTTON_POSY + UI_BUTTON_HEIGHT) {
			QuitButton.setFillColor(BUTTON_HOVER_COLOR);
			return { false, true };
		}
		else {
			RestartButton.setFillColor(BUTTON_COLOR);
			QuitButton.setFillColor(BUTTON_COLOR);
			return { false, false };
		}
	}

	// Draw all Buttons & Texts.
	void DrawUI(RenderWindow& window)
	{
		window.draw(UI_BG_Sprite);
		window.draw(statusText);
		window.draw(RestartButton);
		window.draw(QuitButton);
		window.draw(Flag_Sprite);
		window.draw(FlagText);
		window.draw(RestartText);
		window.draw(QuitText);
	}

	// Update Flag Count & Status Text Based On GameStatus.
	void UpdateUI(int flagCount, GameStatus gameStatus) {
		string s = " : " + to_string(flagCount) + " / " + to_string(MINE_COUNT);
		FlagText.setString(s);
		if (gameStatus == GameStatus::InProgress) {
			statusText.setString(DEFAULT);
			statusText.setFillColor(STATUS_PROGRESS_COLOR);
		}
		else if (gameStatus == GameStatus::Game_Win) {
			statusText.setString(COMPLETE_STATUS);
			statusText.setFillColor(STATUS_COMPLETE_COLOR);
		}
		else {
			statusText.setString(FAILED_STATUS);
			statusText.setFillColor(STATUS_FAILED_COLOR);
		}
	}
};