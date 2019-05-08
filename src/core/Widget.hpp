#pragma once

#include <SFML/Graphics/Shape.hpp>

#include "GUIObject.hpp"

OPEN_CORE_NAMESPACES

class Widget : public GUIObject
{
    DECLARE_GUIOBJECT(Widget)
public:
    Widget(GUIObject* parent = nullptr);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override = 0;

};

CLOSE_CORE_NAMESPACES
