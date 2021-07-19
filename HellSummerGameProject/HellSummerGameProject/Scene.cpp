#include "framework.h"
#include "Scene.h"
#include "Object.h"
#include "TextObject.h"

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:scenes(scenes), window(window), soundSystem(soundSystem)
{
	Init();
}

Scene::~Scene()
{
}

void Scene::Init()
{
}

bool Scene::GetQuit() 
{
	return Quit;
}

void Scene::EndScene()
{
	Quit = true;
}

void Scene::Input(Event* e)
{
}

void Scene::Update(const float& deltaTime)
{
	mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	if (Mouse::isButtonPressed(Mouse::Right))
	{
		cout << mousePosition.x << " " << mousePosition.y << endl;
	}

	for (auto& btn : mButtons)
	{
		btn.second->Update(mousePosition);
	}

	for (auto& obj : animationObjects)
	{
		if (obj->IsActive())
		{
			obj->Update(deltaTime);
			if (obj->GetHitBoxActive())
			{
				obj->UpdateHitBox();
			}
		}
	}

	for (auto& obj : staticObjects)
	{
		if (obj->IsActive())
		{
			obj->Update(deltaTime);
			if (obj->GetHitBoxActive())
			{
				obj->UpdateHitBox();
			}
		}
	}

	/*for (auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}*/
}

void Scene::Render()
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

	/*if (backGround)
	{
		window->draw(*backGround);
	}

	for (auto& obj : vObjects)
	{
		window->draw(*obj);
	}

	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}*/
}