#pragma

#include "GameWindow.h"
#include "Snake.h"

class Game
{
public:
    Game();
    ~Game();
    bool IsGameRunning() const;
    sf::Time Game::GetElapsedTime() const;

    void Update();
    void HandleInput();
    void Render();
    void RestartClock();
private:
    GameWindow m_gameWindow;
    sf::Clock m_clock;
    sf::Time m_elapsedTime;
    Snake snake;
};
