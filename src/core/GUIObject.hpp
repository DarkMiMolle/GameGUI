#pragma once

#include <string_view>
#include <memory>
#include <list>
#include "coreGlobal.hpp"

#define DECLARE_GUIOBJECT(name)                                 \
    public:                                                     \
    static constexpr std::string_view className()               \
    {                                                           \
        return std::string_view(#name);                         \
    }


OPEN_CORE_NAMESPACES

class GUIObject
{
    DECLARE_GUIOBJECT(GUIObject)
public:
    GUIObject(GUIObject* parent = nullptr);
    virtual ~GUIObject();

    const GUIObject* parent() const { return m_parent; }

    void setVisible(bool visible = true);
    bool visible() const;

protected:
    GUIObject* m_parent;
    std::list<GUIObject*> m_children;

    void addChild(GUIObject* child);
    void addChild(std::nullptr_t) = delete;

private:
    bool m_visible;
};

CLOSE_CORE_NAMESPACES
