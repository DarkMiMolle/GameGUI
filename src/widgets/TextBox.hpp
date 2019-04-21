#pragma once

#include <widgetsGlobal.hpp>

#include <functional>

#include <Widget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

OPEN_WIDGETS_NAMESPACES

class TextBox : public core::Widget
{
    DECLARE_GUIOBJECT(TextBox)
public:
    TextBox(const sf::Font &font, const std::string &defaultText = "");
    ~TextBox() override = default;

    std::string text();

    sf::FloatRect rect() const override;
    sf::Vector2f position() const override;
    void setPosition(const sf::Vector2f &position) override;
    void setSize(const sf::Vector2f &size) override;

    void setEnterCallback(const std::function<void(void)>& cb);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
    void doRefresh(const sf::Event& event) override;

private:
    void selected(bool select);

    sf::RectangleShape m_shape;
    sf::Text m_text;

    sf::Color m_selectedColor;
    sf::Color m_neutralColor;

    std::function<void(void)> m_cbEnter;

    unsigned int m_lastChar = 0;
    bool m_selected = false;

};

CLOSE_WIDGETS_NAMESPACES
