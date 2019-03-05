#include "Layout.hpp"
#include <Widget.hpp>

OPEN_CORE_NAMESPACES

Layout::Layout(GUIObject* parent) : GUIObject (parent)
{

}

void Layout::addWidget(Widget *widget)
{
    getItems().push_back(widget);
}

void Layout::addLayout(Layout *layout)
{
    getItems().push_back(layout);
}

void Layout::doVisible(bool visible)
{
    for (auto ptr : m_items)
    {
        if (ptr)
            ptr->setVisible(visible);
    }
}


CLOSE_CORE_NAMESPACES
