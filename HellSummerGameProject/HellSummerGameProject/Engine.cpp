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

	// 시작화면
	this->scenes.push(new StartScene(&scenes,window));
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
			// 현재 실행중인 scene을 종료한다
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