#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 1000), "Window");
    
    Sprite sp;
    Texture tx;
    tx.loadFromFile("Textures/pinkmap.png");
   
    sp.setScale(1.0f, 1.0f);
    sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f);
    sp.setTexture(tx);
    sp.setPosition(500.f, 500.f);


    while (window.isOpen())
    {
        window.clear();

        window.draw(sp);
 
        window.display();
    }
}