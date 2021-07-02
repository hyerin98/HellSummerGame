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

	this->window = new RenderWindow(VideoMode(500, 500), "Oo  Bubble Bobble  oO"); // this�� ���� �ۼ��ϰ� �ִ� Engine�� �ǹ���. Engine�� ������ ��� ��
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
