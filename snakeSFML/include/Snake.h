#pragma

#include <SFML/Graphics.hpp>
#include <vector>

struct SnakeSegment
{
    SnakeSegment(int x, int y): position(x, y) {}
    sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction 
{
    None,
    Up,
    Down,
    Left,
    Right
};

class Snake
{
public:
    Snake(int blockSize);
    ~Snake();

    void SetDirection(Direction direction);
    void Render(sf::RenderWindow& window);
    void Reset();
private:
    sf::RectangleShape m_bodyShapeRect;
    int m_size;
    SnakeContainer m_snakeBody;
    Direction m_currDirection;
};

