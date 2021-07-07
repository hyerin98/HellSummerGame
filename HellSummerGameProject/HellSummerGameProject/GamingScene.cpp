#include "framework.h"
#include "GamingScene.h"
#include "Character.h"
#include "BackgroundObject.h"
#include "ResultScene.h";

GamingScene::GamingScene()
{
	Init();
}

GamingScene::GamingScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

GamingScene::~GamingScene()
{
}

void GamingScene::Init()
{
	vObjects.push_back(new BackgroundObject("Textures/pinkmap.png"));
	vObjects.push_back(new Character);
}

void GamingScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Q:
	{
		scenes->push(new ResultScene(scenes));
		break;
	}
	}
}

void GamingScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void GamingScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
