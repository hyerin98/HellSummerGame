#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(500, 500), "Window");
    window.setFramerateLimit(60);

    IntRect txSq(0, 0, 319 / 3, 424 / 4);
    // 319 x 424
    Texture tx; // 사진을 담고 있는 클래스
    tx.loadFromFile("Textures/DragonFrames.png"); // 그림을 불러온 것

    Sprite sp(tx, txSq); // sprite는 사진을 가지고 움직이게 하는 거
    sp.setScale(3.f, 3.f);

    Clock clock;

    while (window.isOpen())
    {
        window.clear();

        Event e;
        while (window.pollEvent(e));
        {
            switch (e.type)
            {
            case Event::Closed:
            {
                // 윈도우를 종료한다.
                window.close();
                break;
            }
            default:
                break;
            }
        }

        if (clock.getElapsedTime().asSeconds() >= 0.3f)
        {
            if (txSq.left >= 318 - 106)
            {
                txSq.left = 0;
            }
            else
            {
                txSq.left += 319 / 3;
            }
            sp.setTextureRect(txSq);

            clock.restart(); // 0부터 다시 시작 (0.3초마다 if문 실행된다)
        }

        window.draw(sp);
        window.display();
    }
}