#pragma once

#include "widgetsGlobal.hpp"
#include "coreGlobal.hpp"
#include <Widget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <functional>

OPEN_WIDGETS_NAMESPACES

class Button : public core::Widget
{
    DECLARE_GUIOBJECT(Button)
public:
    Button(const std::string& text, const sf::Font& font);
    ~Button() override = default;


    sf::FloatRect rect() const override;
    sf::Vector2f position() const override;
    void setPosition(const sf::Vector2f &position) override;
    void setSize(const sf::Vector2f &size) override;

    void setClickedCallback(const std::function<void(void)>& callback);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
    void doRefresh(const sf::Event& event) override;

private:
    void highlight(bool hl);
    void highlightPressed(bool pressed);

    bool m_highlighted = false;
    bool m_buttonPressed = false;

    sf::RectangleShape m_buttonShape;
    sf::Text m_text;

    sf::Color m_highlitedColor;
    sf::Color m_neutralColor;
    sf::Color m_pressedColor;

    std::function<void(void)> m_callback;

};

CLOSE_WIDGETS_NAMESPACES
