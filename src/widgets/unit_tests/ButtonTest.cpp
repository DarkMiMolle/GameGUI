#include "ButtonTest.hpp"

#include <Button.hpp>

OPEN_WIDGETS_NAMESPACES

TEST_F(ButtonTest, Click)
{
    sf::Font font;
    Button bt("Hello", font);
    bool clicked = false;
    bt.setClickedCallback([&clicked](){ clicked = true;});

    sf::Event event;
    event.type = sf::Event::MouseButtonPressed;
    event.mouseButton.x = 10;
    event.mouseButton.y = 10;
    event.mouseButton.button = sf::Mouse::Left;

    bt.refresh(event);

    EXPECT_FALSE(clicked);

    event.type = sf::Event::MouseButtonReleased;
    bt.refresh(event);

    EXPECT_TRUE(clicked);
}

CLOSE_WIDGETS_NAMESPACES
