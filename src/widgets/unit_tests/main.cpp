#include <gtest/gtest.h>
#include <Config.hpp>

#ifdef CONFIG_BUILD_TEST_GUI
#include <SFML/Graphics.hpp>
#include <Image.hpp>

#include <Button.hpp>
#include <TextBox.hpp>
#include <Layout.hpp>
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

    gameGUI::widgets::Button bt1("Hello", font);
    //bt1.setPosition(sf::Vector2f(10, 10));
    bt1.setClickedCallback([](){
        std::cout << "Hello" << std::endl;
    });

    gameGUI::widgets::TextBox tb(font);

    gameGUI::widgets::Image img;
    img.loadFromFile("data/Tux.png");
    img.setSize(sf::Vector2f(50,50));

    gameGUI::core::Layout ly;
    ly.addWidget(&bt1);
    ly.addWidget(&tb);
    ly.addWidget(&img);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ly.refresh(event);

        window.clear(sf::Color::Black);
        window.draw(ly);
        window.display();
    }

#endif
}
