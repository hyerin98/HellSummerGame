#include "framework.h"
#include "Engine.h"

int main()
{
	Engine engine;

	engine.Render();

	engine.Destroy();

	// 바운딩 박스
	//RenderWindow window(VideoMode(600, 600), "Window");
	//window.setFramerateLimit(60);
	//Event evt;
	//Engine engine;

	//Texture tx;
	//tx.loadFromFile("Textures/test.png");
	//engine.Render();

	//Sprite sp;
	//sp.setPosition(0, 300);
	//sp.setTexture(tx);
	//sp.setOrigin(sp.getGlobalBounds().width / 2.f, sp.getGlobalBounds().height / 2.f);

	//cout << sp.getGlobalBounds().width << " / " << sp.getGlobalBounds().height << endl;

	//Vertex vertice[5];

	//while (window.isOpen())
	//{
	//	window.clear();

	//	while (window.pollEvent(evt))
	//	{
	//		switch (evt.type)
	//		{
	//		case Event::Closed:
	//		{
	//			window.close();
	//			break;
	//		}
	//		default:
	//			break;
	//		}
	//	}

	//	/* Update */

	//	sp.move(Vector2f(1.f, 0));

	//	vertice[0] = Vertex(Vector2f(sp.getGlobalBounds().left, sp.getGlobalBounds().top), Color::Red);
	//	vertice[1] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width, sp.getGlobalBounds().top), Color::Blue);
	//	vertice[2] = Vertex(Vector2f(sp.getGlobalBounds().left + sp.getGlobalBounds().width, sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Magenta);
	//	vertice[3] = Vertex(Vector2f(sp.getGlobalBounds().left, sp.getGlobalBounds().top + sp.getGlobalBounds().height), Color::Green);
	//	vertice[4] = vertice[0];



	//	/* Render */
	//	window.draw(sp);
	//	window.draw(vertice, 5, LinesStrip);
	//	window.display();
}