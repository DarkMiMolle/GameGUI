#pragma once

#include <SFML/Graphics/Shape.hpp>

#include "GUIObject.hpp"

OPEN_CORE_NAMESPACES

class Widget : public GUIObject, public sf::Shape
{
    DECLARE_GUIOBJECT(Widget)
public:
    Widget(GUIObject* parent = nullptr);

    std::size_t getPointCount() const override { return 4; }
    sf::Vector2f getPoint(std::size_t index) const override { return sf::Vector2f(); }

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override = 0;

protected:

};

CLOSE_CORE_NAMESPACES
