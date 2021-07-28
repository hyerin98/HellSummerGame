#include "framework.h"
#include "GamingScene.h"
#include "Character.h"
#include "BackGroundObject.h"
#include "ResultScene.h"
#include "Monster1.h"
#include "Monster2.h"
#include "Monster3.h"
#include "PassPoint.h"

GamingScene::GamingScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void GamingScene::Init()
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

	/*gameView = new View(viewRect);
	gameView->setCenter(character->getPosition());
	window->setView(*gameView);
	gameView->zoom(0.3f);
	 texts["Score"] = new TextObject("Score : ", "Font/BubbleFont.ttf", Vector2f(160.f, 130.f));*/
}

void GamingScene::Destroy()
{
	Scene::Destroy();
	character->Destroy();
}

void GamingScene::Input(Event* e)
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

void GamingScene::Update(const Vector2f& mousePosition)
{
	Scene::Update(mousePosition);
	character->Update(mousePosition);
}

void GamingScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
	character->Update(deltaTime);
	monster1->Update(deltaTime);
	monster2->Update(deltaTime);
	monster3->Update(deltaTime);
	/*gameView->setCenter(character->getPosition());
	window->setView(*gameView);*/

	
}

void GamingScene::Render()
{

	if (backGround)
	{
		window->draw(*backGround);
	}

	Scene::Render();
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
