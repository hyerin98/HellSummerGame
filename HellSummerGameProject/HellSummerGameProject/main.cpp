#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(500, 500), "Window");
    window.setFramerateLimit(60);

    IntRect txSq(0, 0, 319 / 3, 424 / 4);
    // 319 x 424
    Texture tx; // ������ ��� �ִ� Ŭ����
    tx.loadFromFile("Textures/DragonFrames.png"); // �׸��� �ҷ��� ��

    Sprite sp(tx, txSq); // sprite�� ������ ������ �����̰� �ϴ� ��
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
                // �����츦 �����Ѵ�.
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

            clock.restart(); // 0���� �ٽ� ���� (0.3�ʸ��� if�� ����ȴ�)
        }

        window.draw(sp);
        window.display();
    }
}