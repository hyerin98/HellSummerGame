#include "framework.h"
#include "StartScene.h"
#include "BackgroundObject.h"
#include "GamingScene.h"
#include "LobbyScene.h"

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
	music.openFromFile("Sound/start.flac");
	music.play();

	vObjects.push_back(new BackgroundObject("Textures/Title.png"));
	Font* font = new Font;
	font->loadFromFile("Font/BubbleFont.ttf");
	Text* text = new Text("Press Space Key", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getGlobalBounds().width / 2.f, text->getGlobalBounds().height / 2.f);
	text->setPosition(Vector2f(500.f, 690.f));
	mTexts["TEST"] = text;
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
	default:
	{
		scenes->push(new LobbyScene(scenes));
		music.stop();
		break;
	}
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
		mTexts["TEST"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}

	Scene::Update(deltaTime);
}

void StartScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}