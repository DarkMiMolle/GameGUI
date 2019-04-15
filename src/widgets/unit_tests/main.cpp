#include <gtest/gtest.h>
#include <Config.hpp>
//#include "GUIObjectTest.hpp"

#ifdef CONFIG_BUILD_TEST_GUI
#include <SFML/Graphics.hpp>

#include <Button.hpp>
#include <SFML/Window.hpp>
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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");

    sf::Font font;
    font.loadFromFile("/usr/share/fonts/gnu-free/FreeSans.ttf");

    gameGUI::widgets::Button bt("Hello", font);
    bt.setPosition(sf::Vector2f(10, 10));
    bt.setClickedCallback([](){
        std::cout << "Hello" << std::endl;
    });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        bt.refresh(event);

        window.clear(sf::Color::Black);
        window.draw(bt);
        window.display();
    }

#endif
}
