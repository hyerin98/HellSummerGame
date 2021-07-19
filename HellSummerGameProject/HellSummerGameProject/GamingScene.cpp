#include "framework.h"
#include "GamingScene.h"
#include "Character.h"
#include "BackGroundObject.h"
#include "ResultScene.h"
#include "Monster1.h"
#include "Monster2.h"
#include "Monster3.h"
#include "PassPoint.h"

#define PI 3.13459f

GamingScene::GamingScene()
{
	Init();
}

GamingScene::GamingScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

GamingScene::~GamingScene()
{
}

void GamingScene::Init()
{
	backGround = new BackGroundObject("Textures/map.png");
	animationObjects.push_back(new Character);
	animationObjects.push_back(new Monster1);
	animationObjects.push_back(new Monster2);
	animationObjects.push_back(new Monster3);
	animationObjects.push_back(new PassPoint);

	mTexts["Score"] = new TextObject("Score : ", "Font/BubbleFont.ttf", Vector2f(160.f, 130.f));
}

void GamingScene::Destroy()
{
}

void GamingScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Enter:
	{
		scenes->push(new ResultScene(scenes,window, soundSystem));
		break;
	}
	default:
		break;
	}
}

void GamingScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;

	if ((elapsedTime += deltaTime) >= 1.f)
	{
		//staticObjects.data()[5]->setTextureRect(IntRect(0, 0, staticObjects.data()[5]->getTextureRect().width - 10, staticObjects.data()[5]->getTextureRect().height));
		//staticObjects.data()[5]->setPosition(staticObjects.data()[5]->getGlobalBounds().left + staticObjects.data()[2]->getGlobalBounds().width, staticObjects.data()[5]->getPosition().y);
		elapsedTime = 0.f;
	}

	Scene::Update(deltaTime);
}

void GamingScene::Render()
{
	if (backGround)
	{
		window->draw(*backGround);
	}

	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
			if (obj->GetHitBoxActive())
			{
				window->draw(obj->GetHitBox(), 5, LinesStrip);
			}
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			window->draw(*obj);
			if (obj->GetHitBoxActive())
			{
				window->draw(obj->GetHitBox(), 5, LinesStrip);
			}
		}
	}

	for (auto& btn : mButtons)
	{
		window->draw(*btn.second);
	}

	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}

}
