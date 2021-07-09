#include "framework.h"
#include "CharacterScene.h"
#include "Character.h"
#include "Monster1.h"

CharacterScene::CharacterScene()
{
	Init();
}

CharacterScene::CharacterScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

CharacterScene::~CharacterScene()
{
}

void CharacterScene::Init()
{
	vObjects.push_back(new Character);
}

void CharacterScene::Input(Event* e)
{
}

void CharacterScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void CharacterScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
