#include "GUIObjectTest.hpp"
#include <GUIObject.hpp>

OPEN_CORE_NAMESPACES

class RealGUIObject : public GUIObject
{
    DECLARE_GUIOBJECT(RealGUIObject)

    public:
        RealGUIObject() = default;
        ~RealGUIObject() override = default;
};

TEST_F(GUIObjectTest, ClassName)
{
    RealGUIObject gui;
    EXPECT_EQ(gui.className(), "RealGUIObject");
}

CLOSE_CORE_NAMESPACES
