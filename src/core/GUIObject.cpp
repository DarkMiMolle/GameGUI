#include "GUIObject.hpp"

OPEN_CORE_NAMESPACES

GUIObject::GUIObject(GUIObject *parent)
{
    m_parent = parent;

    if (m_parent)
        m_parent->addChild(this);
}

GUIObject::~GUIObject()
{
    for (auto child : m_children)
    {
        if (child)
            child->m_parent = m_parent;
    }
}

void GUIObject::setVisible(bool visible)
{
    m_visible = visible;
    doVisible(visible);
    for (auto child : m_children)
    {
        if (child)
            child->setVisible(visible);
    }
}

bool GUIObject::visible() const
{
    return m_visible;
}

void GUIObject::refresh(const sf::Event &event)
{
    if (!visible())
        return;
    doRefresh(event);
    for (auto child : m_children)
    {
        if (child)
            child->refresh(event);
    }
}

void GUIObject::addChild(GUIObject *child)
{
    m_children.push_back(child);
}

CLOSE_CORE_NAMESPACES
