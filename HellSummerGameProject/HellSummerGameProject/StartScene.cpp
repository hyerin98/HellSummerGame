#include "framework.h"
#include "StartScene.h"
#include "BackgroundObject.h"

StartScene::StartScene()
{
	Init();
}

StartScene::StartScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

StartScene::~StartScene()
{
}

void StartScene::Init()
{
	vObjects.push_back(new BackgroundObject("Textures/Title.png"));
}

void StartScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void StartScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}