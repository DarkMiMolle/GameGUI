#pragma once

#include <SFML/Graphics/Shape.hpp>

#include "GUIObject.hpp"

OPEN_CORE_NAMESPACES

class Widget : public GUIObject, public ::sf::Shape
{
public:
    Widget();
};

CLOSE_CORE_NAMESPACES
