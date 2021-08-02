#include "framework.h"
#include "PracticeScene.h"
#include "JumpObject.h"
#include "PracticeMap.h"
#include "Object.h"
#include "BulletManager.h"

PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void PracticeScene::Init()
{
	vector<int> levels;

	for (int i = 0; i < 50 * 50; ++i)
	{
		levels.push_back(56);
	}

	map = new PracticeMap("Textures/Map/tileSet.png", { 32, 32 }, levels, { 50, 50 });

	mouseCursor = new Object("Textures/Map/tileSet.png");
	mouseCursor->setOrigin({});
	mouseCursor->setTextureRect(map->GetTile(tileNumber));

	player = new JumpObject("Textures/doll.png", { 500.f,500.f });
	bulletMgr = new BulletManager();
}

void PracticeScene::Destroy()
{

}

void PracticeScene::Input(Event* event)
{
	switch (event->type)
	{
	case Event::KeyPressed:
	{
		switch (event->key.code)
		{
		case Keyboard::Space:
		{
			//testBullet->setPosition(player->getPosition()); // 플레이어가 움직여도 그 방향대로 총을 쏠 수 있게
			//testBullet->SetSpeed(200.f);
			//testBullet->SetDirection({ 1.f,0.f });

			bulletMgr->Shoot({1.f, 0.f}, {player->getPosition()}, 200.f);
		}
		case Keyboard::F1:
		{
			map->SaveMap("Test.bin");
			break;
		}
		case Keyboard::F2:
		{
			map->LoadMap("Test.bin");
			break;
		}
		default:
			break;
		}
		break;
	}

	case Event::MouseButtonPressed:
	{
		break;
	}
	case Event::MouseWheelMoved:
	{
		tileNumber += event->mouseWheel.delta;

		if (tileNumber <= 56)
		{
			tileNumber = 56;
		}
		else if (tileNumber >= 56 * 23 - 1)
		{
			tileNumber = 56 * 23 - 1;
		}

		mouseCursor->setTextureRect(map->GetTile(tileNumber));

		break;
	}
	default:
		break;
	}
}

void PracticeScene::Update(const Vector2f& mousePosition)
{
	mouseCursor->setPosition(mousePosition.x + 32, mousePosition.y - 32);
	if (map)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			map->Update(mousePosition, tileNumber);
		}
	}
}

void PracticeScene::Update(const float& deltaTime)
{
	if (mouseCursor)
	{
		mouseCursor->Update(deltaTime);
	}

	if (player)
	{
		player->Update(deltaTime);
	}

	if (bulletMgr)
	{
		bulletMgr->Update(deltaTime);
	}
}

void PracticeScene::Render()
{
	if (map)
	{
		window->draw(*map);
	}

	if (player)
	{
		player->Render(window);
	}

	if (bulletMgr)
	{
		bulletMgr->Render(window);
	}

	if (mouseCursor)
	{
		mouseCursor->Render(window);
	}
}