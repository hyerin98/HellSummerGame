#include "framework.h"
#include "Engine.h"
#include "StartScene.h"

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
	window->setMouseCursorVisible(true);

	this->e = new Event;
	this->timer = new Clock;

	// ������â ������ �ٹ̱�
	Image icon;
	icon.loadFromFile("Textures/icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// �������
	soundSystem = new SoundSystem("Sound/start.flac");
	soundSystem->AddEffectSound("Sound/Click.wav", "Click");
	// ����ȭ��
	scenes.push(new StartScene(&scenes, window, soundSystem));

	soundSystem->Play();
}

void Engine::Destroy()
{
	DELETE(timer);
	DELETE(e);
	DELETE(window);

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
			window->close();
			break;
		}
		case Event::MouseButtonPressed:
		case Event::KeyPressed:
		{
			if (!scenes.empty())
			{
				scenes.top()->Input(e);
			}
		}
		default:
			break;
		}
	}
}

void Engine::Update()
{
	this->deltaTime = timer->getElapsedTime().asSeconds();
	timer->restart();

	Input();

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