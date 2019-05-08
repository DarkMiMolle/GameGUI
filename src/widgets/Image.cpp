#include "Image.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

OPEN_WIDGETS_NAMESPACES

Image::Image()
{
    m_sprite.setPosition(0,0);
}

bool Image::loadFromFile(const std::string &file)
{
    if (!m_texture.loadFromFile(file))
        return false;
    m_sprite.setTexture(m_texture);
    return true;
}

sf::FloatRect Image::rect() const
{
    return m_sprite.getLocalBounds();
}

sf::Vector2f gameGUI::widgets::Image::position() const
{
    return m_sprite.getPosition();
}

void gameGUI::widgets::Image::setPosition(const sf::Vector2f &position)
{
    m_sprite.setPosition(position);
}

void gameGUI::widgets::Image::setSize(const sf::Vector2f &size)
{
    m_sprite.setScale(size.x / m_texture.getSize().x, size.y / m_texture.getSize().y);
}

void gameGUI::widgets::Image::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}


CLOSE_WIDGETS_NAMESPACES
