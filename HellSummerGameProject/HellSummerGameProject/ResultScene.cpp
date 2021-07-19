#include "framework.h"
#include "ResultScene.h"
#include "LobbyScene.h"
#include "StartScene.h"

ResultScene::ResultScene()
{
	Init();
}

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
}
void ResultScene::Destroy()
{
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
}