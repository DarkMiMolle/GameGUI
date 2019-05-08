#include "Layout.hpp"
#include <Widget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

OPEN_CORE_NAMESPACES

Layout::Layout(GUIObject* parent) : GUIObject (parent)
{

}

Layout::Layout(const sf::Vector2f &size, GUIObject *parent) : GUIObject(parent), m_size(size)
{

}

void Layout::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto e : m_items)
    {
        if (e.first)
            target.draw(*e.first, states);
    }
}

void Layout::addWidget(Widget *widget)
{
    getItems().push_back(std::pair<GUIObject*, sf::Vector2f>(widget, sf::Vector2f(0,0)));
    spread();
}

void Layout::addLayout(Layout *layout)
{
    getItems().push_back(std::pair<GUIObject*, sf::Vector2f>(layout, sf::Vector2f(0,0)));
    spread();
}

sf::FloatRect Layout::rect() const
{

}

sf::Vector2f Layout::position() const
{
    return m_position;
}

void Layout::setPosition(const sf::Vector2f &position)
{
    m_position = position;
    spread();
}

void Layout::setSize(const sf::Vector2f &size)
{
    m_size = size;
}

void Layout::doVisible(bool visible)
{
    for (auto& e : m_items)
    {
        if (e.first)
            e.first->setVisible(visible);
    }
}

void Layout::doRefresh(const sf::Event &event)
{
    for (auto& e : m_items)
    {
        if (e.first)
            e.first->refresh(event);
    }
}

void Layout::spread()
{
    sf::Vector2f pos(0,0);

    for (auto& e : m_items)
    {
        e.second = pos;
        e.first->setPosition(position() + e.second);
        pos.x += e.first->rect().width + m_intraMargins.y;
    }
}


CLOSE_CORE_NAMESPACES
