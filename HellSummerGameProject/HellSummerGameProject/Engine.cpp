#include "framework.h"
#include "Engine.h"
#include "StartScene.h"
#include "PracticeScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
	Destroy();
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(1200, 700), "Oo Bubble Bobble oO");
	window->setFramerateLimit(60);
	this->e = new Event;
	this->clock = new Clock;

	// 윈도우창 아이콘 꾸미기
	Image icon;
	icon.loadFromFile("Textures/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	
	soundSystem = new SoundSystem("Sound/Click.wav", false);
	soundSystem->AddEffectSound("Sound/Click.wav", "Click");
	//soundSystem->AddEffectSound("Sound/CoinGet.wav", "CoinGet");

	//scenes.push(new PracticeScene(&scenes, window, soundSystem));
	scenes.push(new StartScene(&scenes, window, soundSystem));
	soundSystem->Play();
}

void Engine::Destroy()
{
	DELETE(clock);
	DELETE(e);
	DELETE(window);

	for (size_t i = 0; i < scenes.size(); ++i)
	{
		scenes.top()->Destroy();
		scenes.top() = nullptr;
		delete scenes.top();
		scenes.pop();
	}
	soundSystem->Destroy();
}

void Engine::Input()
{
	while (window->pollEvent(*e))
	{
		switch (e->type)
		{
		case Event::Closed:
		{
			this->window->close();
			break;
		}
		case Event::KeyPressed:
		case Event::MouseButtonPressed:
		case Event::MouseWheelMoved:
		{
			// Scene InputUpdate();
			if (!scenes.empty())
			{
				scenes.top()->Input(e);
			}
			break;
		}
		default:
			break;
		}
	}
}

void Engine::Update()
{
	this->deltaTime = clock->getElapsedTime().asSeconds();
	clock->restart();
	this->elapsedTime += deltaTime;
	this->mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	if (!scenes.empty())
	{
		if (scenes.top()->GetQuit())
		{
			scenes.top()->Destroy();
			scenes.top() = nullptr;
			delete scenes.top();
			scenes.pop();
		}
		else
		{
			scenes.top()->Update(deltaTime);
			scenes.top()->Update(mousePosition);
		}
	}
	else
	{
		window->close();
	}
}

bool Engine::Render()
{
	if (window->isOpen())
	{
		window->clear();

		Input();
		Update();

		if (!scenes.empty())
		{
			scenes.top()->Render();
		}

		window->display();
		return true;
	}
	else
	{
		return false;
	}
}