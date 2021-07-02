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

	this->window = new RenderWindow(VideoMode(500, 500), "Bubble Bobble"); // this�� ���� �ۼ��ϰ� �ִ� Engine�� �ǹ���. Engine�� ������ ��� ��
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
			default:
				break;
		}
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
