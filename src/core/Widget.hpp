#pragma once

#include <SFML/Graphics/Shape.hpp>

#include "GUIObject.hpp"

OPEN_CORE_NAMESPACES

class Widget : public GUIObject, public ::sf::Shape
{
    DECLARE_GUIOBJECT(Widget)
public:
    Widget(GUIObject* parent = nullptr);

protected:
    void doRefresh() override;
};

CLOSE_CORE_NAMESPACES
