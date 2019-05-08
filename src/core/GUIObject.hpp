#pragma once

#include <string_view>
#include <memory>
#include <list>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
#include "coreGlobal.hpp"

#include <SFML/Graphics/Shape.hpp>

#define DECLARE_GUIOBJECT(name)                                 \
    public:                                                     \
    static constexpr ::std::string_view className()               \
    {                                                           \
        return ::std::string_view(#name);                         \
    }


OPEN_CORE_NAMESPACES

class GUIObject : public sf::Drawable, public sf::Transformable
{
    DECLARE_GUIOBJECT(GUIObject)
public:
    GUIObject(GUIObject* parent = nullptr);
    virtual ~GUIObject();

    virtual const GUIObject* parent() const final { return m_parent; }

    virtual void setVisible(bool visible = true) final;
    virtual bool visible() const final;

    virtual void refresh(const sf::Event& event) final;

    virtual sf::FloatRect rect() const = 0;
    virtual sf::Vector2f position() const = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual void setSize(const sf::Vector2f& size) = 0;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const = 0;
    virtual void doRefresh(const sf::Event& event) = 0;
    virtual void doVisible(bool) {}

private:
    GUIObject* m_parent;
    std::list<GUIObject*> m_children;

    void addChild(GUIObject* child);
    void addChild(std::nullptr_t) = delete;

    bool m_visible = true;
};

CLOSE_CORE_NAMESPACES
