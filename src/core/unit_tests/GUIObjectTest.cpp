#include "GUIObjectTest.hpp"
#include <GUIObject.hpp>

OPEN_CORE_NAMESPACES

class RealGUIObject : public GUIObject
{
    DECLARE_GUIOBJECT(RealGUIObject)

    public:
        RealGUIObject(GUIObject* parent = nullptr) : GUIObject(parent) {}
        ~RealGUIObject() override = default;


    sf::FloatRect rect() const override { return sf::FloatRect(); }
    void setPosition(const sf::Vector2f&) override {}
    void setSize(const sf::Vector2f&) override {}


    protected:
        void doRefresh(const sf::Event& event) override {}
        void doVisible(bool visible) override {}

};

TEST_F(GUIObjectTest, ClassName)
{
    RealGUIObject gui;
    EXPECT_EQ(gui.className(), "RealGUIObject");
}

TEST_F(GUIObjectTest, AddChild)
{
    RealGUIObject gui;
    RealGUIObject* child = new RealGUIObject(&gui);
    RealGUIObject greatChild(child);

    delete child;

    EXPECT_EQ(greatChild.parent(), &gui);
}

CLOSE_CORE_NAMESPACES
