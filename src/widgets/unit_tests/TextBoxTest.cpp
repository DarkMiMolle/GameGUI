#include "TextBoxTest.hpp"

#include <SFML/Graphics/Font.hpp>

#include <TextBox.hpp>

OPEN_WIDGETS_NAMESPACES

TEST_F(TextBoxTest, GetText)
{
    sf::Font font;
    TextBox tb(font, "Hello");

    sf::Event event;
    event.type = sf::Event::MouseButtonReleased;
    event.mouseButton.x = 10;
    event.mouseButton.y = 10;
    event.mouseButton.button = sf::Mouse::Left;
    tb.refresh(event);

    event.type = sf::Event::TextEntered;
    event.text.unicode = 'W';
    tb.refresh(event);

    event.text.unicode = 'o';
    tb.refresh(event);

    event.text.unicode = 'r';
    tb.refresh(event);

    event.text.unicode = 'l';
    tb.refresh(event);

    event.text.unicode = 'd';
    tb.refresh(event);

    EXPECT_EQ(tb.text(), "HelloWorld");
}

TEST_F(TextBoxTest, Enter)
{
    sf::Font font;
    TextBox tb(font, "Hello");

    sf::Event event;
    event.type = sf::Event::MouseButtonReleased;
    event.mouseButton.x = 10;
    event.mouseButton.y = 10;
    event.mouseButton.button = sf::Mouse::Left;
    tb.refresh(event);

    bool m_enter = false;
    tb.setEnterCallback([&m_enter](){ m_enter = true;});
    event.type = sf::Event::TextEntered;
    event.text.unicode = 13; // Enter
    tb.refresh(event);

    EXPECT_TRUE(m_enter);
}

CLOSE_WIDGETS_NAMESPACES
