#include "TextBox.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>

OPEN_WIDGETS_NAMESPACES

TextBox::TextBox(const sf::Font& font, const std::string& defaultText) :
    m_neutralColor(190,190,190), m_selectedColor(210,210,210)
{
    m_text.setFont(font);
    m_text.setString(defaultText);

    m_text.setOrigin((m_text.getLocalBounds().width + m_text.getLocalBounds().left)/2,
                     (m_text.getLocalBounds().height + m_text.getLocalBounds().top)/2);
    m_text.setFillColor(sf::Color::Black);

    m_shape.setSize(sf::Vector2f(100,50));
    m_shape.setFillColor(m_neutralColor);
}

std::string TextBox::text()
{
    return m_text.getString();
}

sf::FloatRect TextBox::rect() const
{
    return m_shape.getLocalBounds();
}

sf::Vector2f TextBox::position() const
{
    return m_shape.getPosition();
}

void TextBox::setPosition(const sf::Vector2f &position)
{
    m_shape.setPosition(position);
    m_text.setPosition(position.x + m_shape.getSize().x/2, position.y + m_shape.getSize().y / 2);
}

void TextBox::setSize(const sf::Vector2f &size)
{
    m_shape.setSize(size);
    m_text.setPosition(m_shape.getPosition().x + m_shape.getSize().x/2, m_shape.getPosition().y + m_shape.getSize().y / 2);
}

void TextBox::setEnterCallback(const std::function<void ()> &cb)
{
    m_cbEnter = cb;
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (!visible())
        return;

    target.draw(m_shape, states);
    target.draw(m_text, states);
}

void TextBox::doRefresh(const sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (rect().contains(event.mouseButton.x - m_shape.getPosition().x, event.mouseButton.y - m_shape.getPosition().y))
            selected(true);
        else
            selected(false);
    }
    if (m_selected)
    {
        if (event.type == sf::Event::KeyReleased &&
                (event.key.code == sf::Keyboard::BackSpace || event.key.code == sf::Keyboard::Enter))
            m_lastChar = 0;
        if (event.type == sf::Event::TextEntered && event.text.unicode != m_lastChar)
        {
            if (event.text.unicode < 128)
            {
                if (event.text.unicode == 8) // BackSpace
                {
                    if (m_text.getString().getSize())
                        m_text.setString(m_text.getString().substring(0, m_text.getString().getSize() - 1));
                }
                else if (event.text.unicode == 13) // Enter
                {
                    if (m_cbEnter)
                        m_cbEnter();
                }
                else if (event.text.unicode == 127) // Delete
                {

                }
                else
                {
                    m_text.setString(m_text.getString() + sf::String(event.text.unicode));
                }

                m_text.setOrigin((m_text.getLocalBounds().width + m_text.getLocalBounds().left)/2,
                                 (m_text.getLocalBounds().height + m_text.getLocalBounds().top)/2);
            }
            m_lastChar = event.text.unicode;

        }
    }
}

void TextBox::selected(bool select)
{
    if (m_selected != select)
    {
        m_selected = select;
        if (m_selected)
            m_shape.setFillColor(m_selectedColor);
        else
            m_shape.setFillColor(m_neutralColor);
    }
}

CLOSE_WIDGETS_NAMESPACES
