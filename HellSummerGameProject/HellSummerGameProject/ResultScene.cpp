#include "framework.h"
#include "ResultScene.h"
#include "LobbyScene.h"
#include "StartScene.h"
#include "BackGroundObject.h"

ResultScene::ResultScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

ResultScene::~ResultScene()
{
}
void ResultScene::Init()
{
	backGround = new BackGroundObject("Textures/result.png");
}
void ResultScene::Destroy()
{
	Scene::Destroy();
}

void ResultScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Escape:
	{
		scenes->top()->EndScene();
		break;
	}
	case Keyboard::Enter:
	{
		scenes->push(new StartScene(scenes, window, soundSystem));
		break;
	}
	default:
		break;
	}
}

void ResultScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}
void ResultScene::Render()
{
	Scene::Render();
	if (backGround)
	{
		window->draw(*backGround);
	}
}