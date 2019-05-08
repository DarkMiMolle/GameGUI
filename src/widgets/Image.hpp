#pragma once

#include <widgetsGlobal.hpp>

#include <Widget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

OPEN_WIDGETS_NAMESPACES

class Image : public core::Widget
{
    DECLARE_GUIOBJECT(Image)
public:
    Image();
    ~Image() override = default;

    bool loadFromFile(const std::string& file);

    // GUIObject interface
public:
    sf::FloatRect rect() const override;
    sf::Vector2f position() const override;
    void setPosition(const sf::Vector2f &position) override;
    void setSize(const sf::Vector2f &size) override;


protected:
    void doRefresh(const sf::Event &event) override {}
    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

CLOSE_WIDGETS_NAMESPACES
