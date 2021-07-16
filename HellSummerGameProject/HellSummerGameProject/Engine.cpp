#include "framework.h"
#include "Engine.h"
#include "StartScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(1200, 700), "Oo Bubble Bobble oO");
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(true);

	Image icon;
	icon.loadFromFile("Textures/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// ����ȭ��
	this->scenes.push(new StartScene(&scenes,window));
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
		case Event::KeyPressed:
		{
			if (!scenes.empty())
			{
				scenes.top()->Input(&e);
			}
		}
		default:
			break;
		}
	}
}

void Engine::Update()
{
	deltaTime = timer.getElapsedTime().asSeconds();
	timer.restart();

	if (!scenes.empty())
	{
		scenes.top()->Update(deltaTime);

		if (this->scenes.top()->GetQuit())
		{
			// ���� �������� scene�� �����Ѵ�
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else
	{
		window->close();
	}
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();

		if (!scenes.empty())
		{
			scenes.top()->Render();
		}
		else
		{
			window->close();
		}
		window->display();
	}
}