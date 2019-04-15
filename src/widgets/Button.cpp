#include "Button.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>

#include <iostream>
OPEN_WIDGETS_NAMESPACES

Button::Button(const std::string &text, const sf::Font& font) :
    m_highlitedColor(230,230,230),
    m_neutralColor(190,190,190),
    m_pressedColor(sf::Color::White)
{
    m_text.setString(text);
    m_text.setFont(font);
    m_text.setOrigin((m_text.getLocalBounds().width + m_text.getLocalBounds().left)/2,
                     (m_text.getLocalBounds().height + m_text.getLocalBounds().top)/2);
    m_buttonShape.setSize(sf::Vector2f(m_text.getLocalBounds().width + m_text.getLocalBounds().left + 20,
                                       m_text.getLocalBounds().height + m_text.getLocalBounds().top + 10));
    m_text.setFillColor(sf::Color::Black);

    m_buttonShape.setFillColor(m_neutralColor);

    setPosition(sf::Vector2f(0,0));
}

sf::FloatRect Button::rect() const
{
    return m_buttonShape.getLocalBounds();
}

void Button::setPosition(const sf::Vector2f &position)
{
    m_buttonShape.setPosition(position);
    m_text.setPosition(position.x + (m_buttonShape.getSize().x - m_text.getLocalBounds().left)/2,
                       position.y + (m_buttonShape.getSize().y - m_text.getLocalBounds().top)/2);
}

void Button::setSize(const sf::Vector2f &size)
{
    m_buttonShape.setSize(size);
}

void Button::setClickedCallback(const std::function<void ()> &callback)
{
    m_callback = callback;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!visible())
        return;

    target.draw(m_buttonShape, states);
    target.draw(m_text, states);
}

void Button::doRefresh(const sf::Event &event)
{
    // If mouse moved, check if it is in the button
    if (event.type == sf::Event::MouseMoved)
    {
        if (rect().contains(event.mouseMove.x - m_buttonShape.getPosition().x, event.mouseMove.y - m_buttonShape.getPosition().y))
            highlight(true);
        else
            highlight(false);
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (rect().contains(event.mouseButton.x - m_buttonShape.getPosition().x, event.mouseButton.y - m_buttonShape.getPosition().y))
            highlightPressed(true);
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (rect().contains(event.mouseButton.x - m_buttonShape.getPosition().x, event.mouseButton.y - m_buttonShape.getPosition().y))
        {
            if (m_callback && m_buttonPressed)
                m_callback();
            highlightPressed(false);
        }
    }
}

void Button::highlight(bool hl)
{
    if (hl != m_highlighted)
    {
        m_highlighted = hl;
        if (m_highlighted)
            m_buttonShape.setFillColor(m_highlitedColor);
        else
            m_buttonShape.setFillColor(m_neutralColor);
    }
}

void Button::highlightPressed(bool pressed)
{
    if (pressed != m_buttonPressed)
    {
        m_buttonPressed = pressed;
        if (m_buttonPressed)
            m_buttonShape.setFillColor(m_pressedColor);
        else
            m_buttonShape.setFillColor(m_highlitedColor);
    }
}


CLOSE_WIDGETS_NAMESPACES
