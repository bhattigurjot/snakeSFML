#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class GameWindow
{
public:
    GameWindow();
    GameWindow(const std::string& title, const sf::Vector2u& size);
    ~GameWindow();

    void Update();
    void BeginDraw();
    void EndDraw();
    void Draw(sf::Drawable& drawable);
    bool IsRunning() const;
    sf::Vector2u GetWindowSize() const;

private:
    void Setup(const std::string& title, const sf::Vector2u& size);
    void Create();
    void Destroy();

    void ToggleFullScreen();

    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isFullScreen;
    bool m_isRunning;

    sf::RenderWindow m_window;
};