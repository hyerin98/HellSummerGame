#include "framework.h"
#include "Engine.h"
#include "StartScene.h"
#include "GamingScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(1000, 800), "Oo Bubble Bobble oO");
	window->setMouseCursorVisible(true);

	Image icon;
	icon.loadFromFile("Textures/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->scenes.push(new Scene);
}

void Engine::Destroy()
{
	if (window)		//if (window != nullptr)
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
			window->close();
			break;

		case Event::KeyPressed:
			switch (e.key.code)
			{
			case Keyboard::Escape:
				window->close();
				break;

			case Keyboard::A:
				this->scenes.push(new StartScene);
				cout << "New Scene : StartScene\n";
				break;

			case Keyboard::D:
				this->scenes.push(new GamingScene);
				cout << "New Scene : GamingScene\n";
				break;

			case Keyboard::Q:
				scenes.top()->EndScene();
				break;

			default:
				break;
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
	Input();
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
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		if (!scenes.empty())
		{
			scenes.top()->Render(window);
		}
		else
		{
			window->close();
		}
		window->display();
	}
}