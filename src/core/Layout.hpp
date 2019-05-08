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
    Layout(const sf::Vector2f& size, GUIObject *parent = nullptr);
    ~Layout() override = default;

    virtual void addWidget(Widget* widget);
    virtual void addLayout(Layout* layout);

    sf::FloatRect rect() const override;
    sf::Vector2f position() const override;
    void setPosition(const sf::Vector2f& position) override;
    void setSize(const sf::Vector2f& size) override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
    void doVisible(bool visible) override;
    void doRefresh(const sf::Event& event) override;

    virtual void spread();

    virtual std::list<std::pair<GUIObject*, sf::Vector2f>>& getItems() { return m_items; }

private:
    std::list<std::pair<GUIObject*, sf::Vector2f>> m_items;
    sf::Vector2f m_size;
    sf::Vector2f m_intraMargins = sf::Vector2f(10,10);
    sf::Vector2f m_position = sf::Vector2f(0,0);
};

CLOSE_CORE_NAMESPACES
