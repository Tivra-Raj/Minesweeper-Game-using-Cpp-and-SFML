#include <SFML/Graphics.hpp>
#include "UI_Manager.cpp"
using namespace std;
using namespace sf;

class GameManager
{
    GameStatus gameStatus;
    Grid grid;
    RenderWindow window;
    UIManager gameUI;

public:

    // Constructor to Initialize
    GameManager()
    {
        gameStatus = GameStatus::InProgress;
        window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE, Style::Close | Style::Titlebar | Style::Fullscreen);
    }

    // Play Game - Main Loop
    void PlayGame()
    {
        Grid* gameGrid = new Grid;
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    // If the user clicked the close window button
                case Event::Closed:
                {
                    // We close the window
                    window.close();
                    break;
                }

                case Event::MouseButtonReleased:
                {
                    switch (event.mouseButton.button)
                    {
                        // If the LMB is released
                    case Mouse::Left:
                    {
                        if (gameStatus == GameStatus::InProgress)
                        {
                            Vector2i mousePosition = Mouse::getPosition(window);
                            // We open the cell under the cursor
                            gameGrid->open_cell(mousePosition, gameStatus);
                        }

                        pair<bool, bool> isButtonsClicked = gameUI.UpdateButtonOnHover(sf::Mouse::getPosition(window));

                        if (isButtonsClicked.first)
                        {
                            gameGrid->ResetGrid();
                            gameUI.UpdateUI(MINE_COUNT, gameStatus);
                            gameStatus = GameStatus::InProgress;
                        }
                        else if (isButtonsClicked.second)
                        {
                            window.close();
                        }

                        break;
                    }

                    // If the RMB is released
                    case Mouse::Right:
                    {
                        if (gameStatus == GameStatus::InProgress)
                        {
                            Vector2i mousePosition = Mouse::getPosition(window);
                            // We open the cell under the cursor
                            gameGrid->PlaceFlag(mousePosition);
                        }
                        break;
                    }
                    }
                    break;
                }
                }
            }


            gameUI.UpdateButtonOnHover(sf::Mouse::getPosition(window));
            gameUI.UpdateUI(gameGrid->getFlagCount(), gameStatus);
            window.clear();
            gameGrid->DrawGrid(window, gameStatus);
            gameUI.DrawUI(window);
            window.display();
        }
    }

};