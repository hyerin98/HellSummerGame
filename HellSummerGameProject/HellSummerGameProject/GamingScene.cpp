#include "framework.h"
#include "GamingScene.h"
#include "Character.h"
#include "BackgroundObject.h"
#include "ResultScene.h"; 
#include "Monster1.h"
#include "Monster2.h"
#include "Monster3.h"
#include "PassPoint.h"

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
	music.openFromFile("Sound/gaming.flac");
	music.play();

	vObjects.push_back(new BackgroundObject("Textures/pinkmap.png"));
	vObjects.push_back(new Character);
	vObjects.push_back(new Monster1);
	vObjects.push_back(new Monster2);
	vObjects.push_back(new Monster3);
	vObjects.push_back(new PassPoint);
}

void GamingScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Q:
	{
		scenes->push(new ResultScene(scenes));
		music.stop();
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
