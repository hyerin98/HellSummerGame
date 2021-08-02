#include "framework.h"
#include "GamingScene1.h"
#include "Character.h"
#include "BackGroundObject.h"
#include "GamingScene2.h"
#include "Monster1.h"
#include "Monster2.h"
#include "Monster3.h"
#include "PassPoint.h"
#include "BulletManager.h"

GamingScene1::GamingScene1(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void GamingScene1::Init()
{
	backGround = new BackGroundObject("Textures/map.png");
	
	character = new Character(PLAYER_BUBBLUN);
	character->setScale(0.18f, 0.18f);

	monster1 = new Monster1(MONSTER_MONSTER1);
	monster1->setScale(0.2f, 0.2f);

	monster2 = new Monster2(MONSTER_MONSTER2);
	monster2->setScale(0.18f, 0.18f);

	monster3 = new Monster3(MONSTER_MONSTER3);
	monster3->setScale(0.18f, 0.18f);

	portal = new Object("Textures/portal.png");
	portal->setPosition(1080.f, 600.f);

	/*gameView = new View(viewRect);
	gameView->setCenter(character->getPosition());
	window->setView(*gameView);
	gameView->zoom(0.3f);
	 texts["Score"] = new TextObject("Score : ", "Font/BubbleFont.ttf", Vector2f(160.f, 130.f));*/
}

void GamingScene1::Destroy()
{
	Scene::Destroy();
	character->Destroy();
}

void GamingScene1::Input(Event* e)
{
	switch (e->type)
	{
	case Event::KeyPressed:
	{
		switch (e->key.code)
		{
		case Keyboard::Escape:
		{
			EndScene();
			break;
		}
		case Keyboard::F1:
		{
			soundSystem->VolumeDown();
			break;
		}
		case Keyboard::F2:
		{
			soundSystem->VolumeUp();
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}

void GamingScene1::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
	character->Update(mousePosition);
}

void GamingScene1::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
	character->Update(deltaTime);
	monster1->Update(deltaTime);
	monster2->Update(deltaTime);
	monster3->Update(deltaTime);
	portal->Update(deltaTime);

	if (character && portal)
	{
		if (portal->getGlobalBounds().contains(character->getPosition()))
		{
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				scenes->push(new GamingScene2(scenes, window, soundSystem));
			}
		}
	}
	/*gameView->setCenter(character->getPosition());
	window->setView(*gameView);*/	
}

void GamingScene1::Render()
{
	if (backGround)
	{
		window->draw(*backGround);
	}

	Scene::Render();

	if (portal)
	{
		portal->Render(window);
	}

	if (character)
	{
		character->Render(window);
	}

	if (monster1)
	{
		monster1->Render(window);
	}

	if (monster2)
	{
		monster2->Render(window);
	}

	if (monster3)
	{
		monster3->Render(window);
	}

	for (auto& btn : buttons)
	{
		window->draw(*btn.second);
	}

	for (auto& txt : texts)
	{
		window->draw(*txt.second);
	}

}
