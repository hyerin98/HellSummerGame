#include "framework.h"
#include "Engine.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	// 현재 window 변수는 포인터로 존재한다.

	this->window = new RenderWindow(VideoMode(500, 500), "Oo Bubble Bobble oO"); // this는 현재 작성하고 있는 Engine을 의미함. Engine의 윈도우 라는 뜻
	window->setMouseCursorVisible(false); // 마우스 커서 안보이게함 (false)
	Image icon;
	icon.loadFromFile("Textures/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Engine::Destroy()
{
	// 윈도우가 nullptr이 아니라면
	if (window)
	{
		delete window;
	}
}

void Engine::Input()
{
	// 이벤트들은 여기에다 쓴다.
	// 외부로부터 event가 들어왔음 input임
	// input은 업데이트의 일부분이다. 왜냐면 매 프레임 실행될것이니까.
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		case Event::MouseButtonPressed:
		{
			window->setTitle("Click"); // 클릭하면 윈도우 타이틀 바뀜
			break;
		}
		case Event::KeyPressed:
		{
			switch (e.key.code)
			{
			case Keyboard::A:
			{
				cout << "Pressed A key !!\n";
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}

	// KeyBoard Input
	if (Keyboard::isKeyPressed(Keyboard::Escape)) // Esc누르면 종료
	{
		window->close();
	}

	// Mouse Input
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		window->setTitle("Left Click");
	}
	else if (Mouse::isButtonPressed(Mouse::Right))
	{
		window->setTitle("Right Click");
	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds(); // 시간도 업데이트해준다
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		window->display();
	}
}
