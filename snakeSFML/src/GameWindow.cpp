#include "GameWindow.h"

GameWindow::GameWindow()
{
    Setup("Default Game Window", sf::Vector2u(640, 480));
}

GameWindow::GameWindow(const std::string& title, const sf::Vector2u& size)
{
    Setup(title, size);
}

GameWindow::~GameWindow()
{
    Destroy();
}

// Getters
bool GameWindow::IsRunning() const { return m_isRunning; }
sf::Vector2u GameWindow::GetWindowSize() const { return m_windowSize; }

// Public Functions
void GameWindow::BeginDraw() 
{
    m_window.clear(sf::Color::Black);
}

void GameWindow::EndDraw() 
{
    m_window.display();
}

void GameWindow::Draw(sf::Drawable& drawable)
{
    m_window.draw(drawable);
}

void GameWindow::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_isRunning = false;
            Destroy();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) // Press F5 to ToggleFullscreen
        {
            ToggleFullScreen();
        }
    }
}

// Private Functions
void GameWindow::Setup(const std::string& title, const sf::Vector2u& size)
{
    m_windowTitle = title;
    m_windowSize = size;
    m_isFullScreen = false;
    m_isRunning = true;

    // Framerate
    m_window.setFramerateLimit(60);

    Create();
}

void GameWindow::Create()
{
    // Create Window
    auto style = m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default;
    m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), m_windowTitle, style);
}

void GameWindow::Destroy()
{
    m_window.close();
}

void GameWindow::ToggleFullScreen()
{
    m_isFullScreen = !m_isFullScreen;
    Destroy();
    Create();
}