#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(sf::VideoMode(500, 500), "Window");
    window.setFramerateLimit(60);

    vector<Texture> txVector; // push_back�� �̿��Ͽ� ����ٰ� ����

    Texture tx;
    char name[50];

    for (int i = 32; i <= 35; ++i)
    {
        sprintf(name, "Textures/cookie0020x2/cookie0020x2_00%d.png\n", i);
        tx.loadFromFile(name);
        txVector.push_back(tx); // push_back�� ����Ʈ�ȿ� �־��ִ� ����
    }
    
    Sprite sp;

    Clock clock;

    size_t keyFrameTime = 0;

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

        if (clock.getElapsedTime().asSeconds() > 0.2f)
        {
            sp.setTexture(txVector.data()[++keyFrameTime % txVector.size()]);
            clock.restart();
        }
        window.draw(sp);
        window.display();
    }
}