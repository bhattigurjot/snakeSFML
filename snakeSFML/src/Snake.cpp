#include "Snake.h"

Snake::Snake(int blockSize): m_size(blockSize)
{
    m_bodyShapeRect.setSize(sf::Vector2f(static_cast<float>(m_size-1), static_cast<float>(m_size-1)));
    Reset();
}

Snake::~Snake() {}

// Getters and Setters
void Snake::SetDirection(Direction direction) { m_currDirection = direction; }

// Public functions
void Snake::Render(sf::RenderWindow& window)
{
    if (m_snakeBody.empty()) return;
    // Draw head
    auto head = m_snakeBody.begin();
    m_bodyShapeRect.setFillColor(sf::Color::Yellow);
    m_bodyShapeRect.setPosition(static_cast<float>(head->position.x * m_size), static_cast<float>(head->position.y * m_size));
    window.draw(m_bodyShapeRect);
    // Draw rest of the snake's body
    m_bodyShapeRect.setFillColor(sf::Color::Green);
    for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
    {
        m_bodyShapeRect.setPosition(static_cast<float>(itr->position.x * m_size), static_cast<float>(itr->position.y * m_size));
        window.draw(m_bodyShapeRect);
    }
}

void Snake::Reset()
{
    m_snakeBody.clear();
    m_snakeBody.push_back(SnakeSegment(5,7));
    m_snakeBody.push_back(SnakeSegment(5,6));
    m_snakeBody.push_back(SnakeSegment(5,5));
    SetDirection(Direction::None);
}