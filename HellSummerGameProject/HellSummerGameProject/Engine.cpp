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
	// ���� window ������ �����ͷ� �����Ѵ�.

	this->window = new RenderWindow(VideoMode(500, 500), "Oo Bubble Bobble oO"); // this�� ���� �ۼ��ϰ� �ִ� Engine�� �ǹ���. Engine�� ������ ��� ��
	window->setMouseCursorVisible(false); // ���콺 Ŀ�� �Ⱥ��̰��� (false)
	Image icon;
	icon.loadFromFile("Textures/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Engine::Destroy()
{
	// �����찡 nullptr�� �ƴ϶��
	if (window)
	{
		delete window;
	}
}

void Engine::Input()
{
	// �̺�Ʈ���� ���⿡�� ����.
	// �ܺηκ��� event�� ������ input��
	// input�� ������Ʈ�� �Ϻκ��̴�. �ֳĸ� �� ������ ����ɰ��̴ϱ�.
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
			window->setTitle("Click"); // Ŭ���ϸ� ������ Ÿ��Ʋ �ٲ�
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
	if (Keyboard::isKeyPressed(Keyboard::Escape)) // Esc������ ����
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
	deltaTime = timer.getElapsedTime().asSeconds(); // �ð��� ������Ʈ���ش�
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
