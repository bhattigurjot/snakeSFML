#include "Game.h"

Game::Game() : m_gameWindow("Test Game", sf::Vector2u(800, 600)), snake(16)
{
}

Game::~Game()
{
}

// Getters
bool Game::IsGameRunning() const { return m_gameWindow.IsRunning(); }
sf::Time Game::GetElapsedTime() const { return m_elapsedTime; }

// Public Functions
void Game::HandleInput()
{

}

void Game::Update()
{
    m_gameWindow.Update();
}

void Game::Render()
{
    m_gameWindow.BeginDraw();
    // m_gameWindow.Draw(sf::RectangleShape({100,100}));
    snake.Render(*m_gameWindow.GetRenderWindow());
    m_gameWindow.EndDraw();
}

void Game::RestartClock()
{
    m_elapsedTime = m_clock.restart();
}