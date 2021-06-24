#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(500, 300), "Window");

    // 사각형 오브젝트
    // 사이즈는 100.f x 100.f
    // 색상은 Green
    // 위치는 100.f, 100.f
    RectangleShape rs;

    // Vector2f=float 자료형 두개 짜리
    rs.setFillColor(Color::Green);
    rs.setSize(Vector2f(100.f, 100.f));
    rs.setPosition(Vector2f(250.f, 250.f));
    // 오브젝트의 중심을 set하는 함수
    rs.setOrigin(rs.getSize() / 2.f);


    while (window.isOpen())
    {
        window.clear();

        //rs.setPosition(rs.getPosition().x + .5f, rs.getPosition().y);

        // rs를 윈도우에 그려라!
        window.draw(rs);

        // 윈도우에 그린 결과물을 출력해라!
        window.display();
    }
}