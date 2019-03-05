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

    virtual const GUIObject* parent() const final { return m_parent; }

    virtual void setVisible(bool visible = true) final;
    virtual bool visible() const final;

    virtual void refresh() final;

protected:
    virtual void doRefresh() = 0;
    virtual void doVisible(bool visible) {}

private:
    GUIObject* m_parent;
    std::list<GUIObject*> m_children;

    void addChild(GUIObject* child);
    void addChild(std::nullptr_t) = delete;

    bool m_visible;
};

CLOSE_CORE_NAMESPACES
