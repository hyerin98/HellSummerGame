#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 1000), "Window");

    Sprite Stage;
    Texture tx;
    tx.loadFromFile("Textures/pinkmap.png");
    Stage.setScale(3.0f, 3.0f);
    Stage.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f);
    Stage.setTexture(tx);
    Stage.setPosition(500.f, 500.f);

    Sprite bubble;
    Texture ob;

    ob.loadFromFile("Textures/bubblebobbleright.png");
    bubble.setScale(0.4f, 0.4f);
    bubble.setOrigin(ob.getSize().x / 2.f, ob.getSize().y / 2.f);
    bubble.setTexture(ob);
    bubble.setPosition(500.f, 755.f);


    while (window.isOpen())
    {
        window.clear();

        window.draw(Stage);
        window.draw(bubble);

        Event e;
        while (window.pollEvent(e))
        {

            switch (e.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Left) == true)
                {
                    ob.loadFromFile("Textures/bubblebobbleleft.png");
                    bubble.move(-10.0f, 0.0f);
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) == true)
                {
                    ob.loadFromFile("Textures/bubblebobbleright.png");
                    bubble.move(10.0f, 0.0f);
                }
                break;
            default:
                break;
            }
        }

        window.display();
    }
}