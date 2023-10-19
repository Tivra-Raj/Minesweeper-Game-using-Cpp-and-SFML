#include <SFML/Graphics.hpp>
#include "Cell_Manager.cpp"

class UIManager
{
	Texture UIBgTexture;
	Sprite UI_BG_Sprite;

	Font gameTitleFont;
	Text gameTitleText;

	Font creatorNameFont;
	Text creatorNameText;

	Font buttonFont;

	Texture RestartButtonTexture;
	Sprite Restart_Button_Sprite;
	Text RestartText;

	Texture QuitButtonTexture;
	Sprite Quit_Button_Sprite;
	Text QuitText;

	Texture flagTexture;
	Sprite Flag_Sprite;
	Text FlagText;

	Font statusFont;
	Text statusText;

	Texture InProgrssEmojiTexture;
	Texture GameWonEmojiTexture;
	Texture GameOverEmojiTexture;
	Sprite INPROGRESS_EMOJI_Sprite;
	Sprite GAMEWON_EMOJI_Sprite;
	Sprite GAMEOVER_EMOJI_Sprite;

public:
	// Constructor To Initialize All Elements.
	UIManager()
	{
		Vector2f targetSize(SPRITE_SIZE, SPRITE_SIZE);

		//font
		gameTitleFont.loadFromFile(GAME_TITLE_FONT_PATH);
		creatorNameFont.loadFromFile(CREATOR_NAME_FONT_PATH);
		buttonFont.loadFromFile(BUTTON_FONT);

		//UI
		UIBgTexture.loadFromFile(UIBG_SPRITE_PATH);
		UI_BG_Sprite.setTexture(UIBgTexture);
		UI_BG_Sprite.setScale(1.2f, 2.7f);
		UI_BG_Sprite.setPosition(UIBG_SPRITE_POSX, UIBG_SPRITE_POSY);

		//Game Title
		gameTitleText.setFont(gameTitleFont);
		gameTitleText.setFillColor(GAME_TITLE_COLOR);
		gameTitleText.setCharacterSize(GAME_TITLE_FONT_SIZE);
		gameTitleText.setString(GAME_TITLE_TEXT);
		gameTitleText.setPosition(GAME_TITLE_TEXT_POS);

		//Creator Name
		creatorNameText.setFont(creatorNameFont);
		creatorNameText.setFillColor(CREATOR_NAME_COLOR);
		creatorNameText.setCharacterSize(CREATOR_NAME_FONT_SIZE);
		creatorNameText.setString(CREATOR_NAME_TEXT);
		creatorNameText.setPosition(CREATOR_NAME_TEXT_POS);

		//Restart Button
		RestartButtonTexture.loadFromFile(UI_BUTTON_SPRITE_PATH);
		Restart_Button_Sprite.setTexture(RestartButtonTexture);
		Restart_Button_Sprite.setScale(UI_BUTTON_WIDTH, UI_BUTTON_HEIGHT);
		Restart_Button_Sprite.setPosition(RESTART_BUTTON_POSX, RESTART_BUTTON_POSY);

		//Restart Text
		RestartText.setFont(buttonFont);
		RestartText.setFillColor(BUTTON_TEXT_COLOR);
		RestartText.setCharacterSize(BUTTON_TEXT_SIZE);
		RestartText.setString(RESTART_BUTTON_TEXT);
		RestartText.setPosition(RESTART_TEXT_POS);

		// QUIT BUTTON
		QuitButtonTexture.loadFromFile(UI_BUTTON_SPRITE_PATH);
		Quit_Button_Sprite.setTexture(QuitButtonTexture);
		Quit_Button_Sprite.setScale(UI_BUTTON_WIDTH, UI_BUTTON_HEIGHT);
		Quit_Button_Sprite.setPosition(QUIT_BUTTON_POSX, QUIT_BUTTON_POSY);

		// QUIT TEXT
		QuitText.setFont(buttonFont);
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
		FlagText.setFont(buttonFont);
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

		// EMOJI
		InProgrssEmojiTexture.loadFromFile(INPROGRESS_EMOJI_SPRITE_PATH);
		INPROGRESS_EMOJI_Sprite.setTexture(InProgrssEmojiTexture);
		INPROGRESS_EMOJI_Sprite.setScale(targetSize.x / INPROGRESS_EMOJI_Sprite.getLocalBounds().width, targetSize.y / INPROGRESS_EMOJI_Sprite.getLocalBounds().height);
		INPROGRESS_EMOJI_Sprite.setPosition(EMOJI_SPRITE_POSX, EMOJI_SPRITE_POSY);

		GameWonEmojiTexture.loadFromFile(GAMEWON_EMOJI_SPRITE_PATH);
		GAMEWON_EMOJI_Sprite.setTexture(GameWonEmojiTexture);
		GAMEWON_EMOJI_Sprite.setScale(targetSize.x / GAMEWON_EMOJI_Sprite.getLocalBounds().width, targetSize.y / GAMEWON_EMOJI_Sprite.getLocalBounds().height);
		GAMEWON_EMOJI_Sprite.setPosition(EMOJI_SPRITE_POSX, EMOJI_SPRITE_POSY);

		GameOverEmojiTexture.loadFromFile(GAMEOVER_EMOJI_SPRITE_PATH);
		GAMEOVER_EMOJI_Sprite.setTexture(GameOverEmojiTexture);
		GAMEOVER_EMOJI_Sprite.setScale(targetSize.x / GAMEOVER_EMOJI_Sprite.getLocalBounds().width, targetSize.y / GAMEOVER_EMOJI_Sprite.getLocalBounds().height);
		GAMEOVER_EMOJI_Sprite.setPosition(EMOJI_SPRITE_POSX, EMOJI_SPRITE_POSY);
	}

	// Checks & Updates Restart & Quit Buttons on Hover. Also returns true if hovering.
	pair<bool, bool> UpdateButtonOnHover(Vector2i mouse_pos) 
	{
		float pos_x = mouse_pos.x;
		float pos_y = mouse_pos.y;
		if (pos_x > RESTART_BUTTON_POSX && pos_x < RESTART_BUTTON_POSX + 305 && pos_y > RESTART_BUTTON_POSY && pos_y < RESTART_BUTTON_POSY + 95) 
		{
			Restart_Button_Sprite.setScale(UI_BUTTON_HOVERED_WIDTH, UI_BUTTON_HOVERED_HEIGHT);
			Restart_Button_Sprite.setPosition(1350, 695);
			RestartText.setFillColor(Color::Yellow);
			return { true, false };
		}
		else if (pos_x > QUIT_BUTTON_POSX && pos_x < QUIT_BUTTON_POSX + 305 && pos_y > QUIT_BUTTON_POSY && pos_y < QUIT_BUTTON_POSY + 95)
		{
			Quit_Button_Sprite.setScale(UI_BUTTON_HOVERED_WIDTH, UI_BUTTON_HOVERED_HEIGHT);
			Quit_Button_Sprite.setPosition(1350, 845);
			QuitText.setFillColor(Color::Yellow);
			return { false, true };
		}
		else 
		{
			Restart_Button_Sprite.setScale(UI_BUTTON_WIDTH, UI_BUTTON_HEIGHT);
			Restart_Button_Sprite.setPosition(RESTART_BUTTON_POSX, RESTART_BUTTON_POSY);
			RestartText.setFillColor(BUTTON_TEXT_COLOR);

			Quit_Button_Sprite.setScale(UI_BUTTON_WIDTH, UI_BUTTON_HEIGHT);
			Quit_Button_Sprite.setPosition(QUIT_BUTTON_POSX, QUIT_BUTTON_POSY);
			QuitText.setFillColor(BUTTON_TEXT_COLOR);
			return { false, false };
		}
	}

	// Draw all Buttons & Texts.
	void DrawUI(RenderWindow& window, GameStatus gameStatus)
	{
		window.draw(UI_BG_Sprite);

		window.draw(gameTitleText);
		window.draw(creatorNameText);

		window.draw(Restart_Button_Sprite);
		window.draw(RestartText);

		window.draw(Quit_Button_Sprite);
		window.draw(QuitText);
		
		window.draw(Flag_Sprite);
		window.draw(FlagText);

		window.draw(statusText);

		if (gameStatus == GameStatus::InProgress) 
		{
			window.draw(INPROGRESS_EMOJI_Sprite);
		}
		else if (gameStatus == GameStatus::Game_Win) 
		{
			window.draw(GAMEWON_EMOJI_Sprite);
		}
		else 
		{
			window.draw(GAMEOVER_EMOJI_Sprite);
		}
	}

	// Update Flag Count & Status Text Based On GameStatus.
	void UpdateUI(int flagCount, GameStatus gameStatus)
	{
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