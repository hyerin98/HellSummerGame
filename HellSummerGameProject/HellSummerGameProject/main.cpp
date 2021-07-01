#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 1000), "Oo  Bubble Bobble  oO");


    Sprite Stage;
    Texture tx;
    tx.loadFromFile("Textures/pinkmap.png");
    Stage.setScale(1.0f, 1.0f);
    Stage.setScale(3.0f, 3.0f);
    Stage.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f);
    Stage.setTexture(tx);
    Stage.setPosition(500.f, 500.f);


    Sprite bubble1;
    Texture ob1;
    ob1.loadFromFile("Textures/bubblebobbleright.png");
    bubble1.setScale(0.4f, 0.4f);
    bubble1.setOrigin(ob1.getSize().x / 2.f, ob1.getSize().y / 2.f);
    bubble1.setTexture(ob1);
    bubble1.setPosition(500.f, 755.f);

    Sprite bubble2;
    Texture ob2;
    ob2.loadFromFile("Textures/bubblebobble2right.png");
    bubble2.setScale(0.22f, 0.22f);
    bubble2.setOrigin(ob2.getSize().x / 2.f, ob2.getSize().y / 2.f);
    bubble2.setTexture(ob2);
    bubble2.setPosition(600.f, 370.f);


    while (window.isOpen())
    {
        window.clear();
        window.draw(Stage);
        window.draw(bubble1);
        window.draw(bubble2);

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
                    ob1.loadFromFile("Textures/bubblebobbleleft.png");
                    bubble1.move(-10.0f, 0.0f);
                }
                else if (Keyboard::isKeyPressed(Keyboard::Right) == true)
                {
                    ob1.loadFromFile("Textures/bubblebobbleright.png");
                    bubble1.move(10.0f, 0.0f);
                }
                else if (Keyboard::isKeyPressed(Keyboard::A) == true)
                {
                    ob2.loadFromFile("Textures/bubblebobble2left.png");
                    bubble2.move(-10.0f, 0.0f);
                }
                else if (Keyboard::isKeyPressed(Keyboard::D) == true)
                {
                    ob2.loadFromFile("Textures/bubblebobble2right.png");
                    bubble2.move(10.f, 0.0f);
                }
                
                break;
            default:
                break;
            }
        }

        window.display();
    }
}