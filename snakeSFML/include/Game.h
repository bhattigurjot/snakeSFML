#pragma

#include "GameWindow.h"

class Game
{
public:
    Game();
    ~Game();
    bool IsGameRunning();
    void Update();
    void HandleInput();
    void Render();

private:
    GameWindow m_gameWindow;
};
