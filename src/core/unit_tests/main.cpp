#include <gtest/gtest.h>
#include <Config.hpp>
#include "GUIObjectTest.hpp"

#ifdef CONFIG_BUILD_TEST_GUI
#include <SFML/Graphics.hpp>
#endif

void manualTest();

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int testRet = RUN_ALL_TESTS();
    if (testRet == 0)
    {
        manualTest();

        return 0;
    }
    return testRet;
}

void manualTest()
{
#ifdef CONFIG_BUILD_TEST_GUI
    sf::Window window(sf::VideoMode(800, 600), "Test Window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

#endif
}
