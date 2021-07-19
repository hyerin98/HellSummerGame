#include "framework.h"
#include "StartScene.h"
#include "BackGroundObject.h"
#include "LobbyScene.h"

StartScene::StartScene()
{
	Init();
}

StartScene::StartScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

StartScene::~StartScene()
{
}

void StartScene::Init()
{
	backGround = new BackGroundObject("Textures/Title.png");

	mTexts["TITLE"] = new TextObject("Press Enter Keys!!", "Font/BubbleFont.ttf", Vector2f(600.f, 590.f));
}

void StartScene::Destroy()
{
}

void StartScene::Input(Event* e)
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
		scenes->push(new LobbyScene(scenes, window, soundSystem));
		break;
	}
	default:
		break;
	}
}

void StartScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;
	static float txtScale = 1.f;
	static int frame = 0;
	static int div = 1;

	if ((elapsedTime += deltaTime) >= 0.02f)
	{
		if ((++frame % 30) == 0)
		{
			div *= -1;
		}

		txtScale += (0.01f * div);
		mTexts["TITLE"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}
	Scene::Update(deltaTime);
}

void StartScene::Render()
{
	Scene::Render();
}