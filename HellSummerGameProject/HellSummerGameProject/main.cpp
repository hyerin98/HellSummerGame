#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(500, 500), "Window");

    // 절대사이즈가 없다.
    // Scaling
    // texture의 사이즈를그대로 가져오기 때문에
    // 이를 배수를 곱해서 줄이거나 늘릴 수 있음
    Sprite sp;
    Texture tx;
    tx.loadFromFile("Textures/images.jfif");

    sp.setScale(0.5f, 0.5f);
    sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f);
    sp.setTexture(tx);
    sp.setPosition(250.f, 250.f);


    while (window.isOpen())
    {
        window.clear();
       
        window.draw(sp);

        window.display();
    }
}