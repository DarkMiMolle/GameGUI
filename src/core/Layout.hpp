#pragma once

#include <memory>
#include <list>

#include "coreGlobal.hpp"
#include "GUIObject.hpp"

OPEN_CORE_NAMESPACES

class Widget;

class Layout : public GUIObject
{
    DECLARE_GUIOBJECT(Layout)
public:
    Layout(GUIObject *parent = nullptr);
    ~Layout() override = default;

    virtual void addWidget(Widget* widget);
    virtual void addLayout(Layout* layout);

protected:
    void doVisible(bool visible) override;

    virtual std::list<GUIObject*>& getItems() { return m_items; }

private:
    std::list<GUIObject*> m_items;
};

CLOSE_CORE_NAMESPACES
