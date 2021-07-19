#include "framework.h"
#include "LobbyScene.h"
#include "BackGroundObject.h"
#include "GamingScene.h"

LobbyScene::LobbyScene()
{
	Init();
}

LobbyScene::LobbyScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	backGround = new BackGroundObject("Textures/lobby.png");
	/*Font* font = new Font;
	font->loadFromFile("Font/BubbleFont.ttf");
	Text* text = new Text("Press Space Key!!", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getGlobalBounds().width / 2.f, text->getGlobalBounds().height / 2.f);
	text->setPosition(Vector2f(600.f, 590.f));
	mTexts["TEST"] = text;*/
}

void LobbyScene::Destroy()
{
}

void LobbyScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Enter:
	{
		scenes->push(new GamingScene(scenes,window, soundSystem));
		break;
	}
	default:
		break;
	}
}

void LobbyScene::Update(const float& deltaTime)
{
	/*static float elapsedTime = 0.f;

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
	}*/

	Scene::Update(deltaTime);
}

void LobbyScene::Render()
{
	Scene::Render();
}