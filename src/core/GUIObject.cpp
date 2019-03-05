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

void GUIObject::refresh()
{
    doRefresh();
    for (auto child : m_children)
    {
        if (child)
            child->refresh();
    }
}

void GUIObject::addChild(GUIObject *child)
{
    m_children.push_back(child);
}

CLOSE_CORE_NAMESPACES
