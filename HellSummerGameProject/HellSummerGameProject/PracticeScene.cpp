#include "framework.h"
#include "PracticeScene.h"
#include "Button.h"
#include "GamingScene.h"

PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window, soundSystem)
{
	Init();
}

void PracticeScene::Init()
{

	bts["Button!"] = new Button("Textures/startbutton1.png","Textures/startbutton2.png", { 200.f,200.f });
	
	doll = new Object("Textures/test.png");
	portal = new Object("Textures/04.png");

	doll->setPosition(500.f, 500.f);
	portal->setPosition(50.f, 500.f);
	
}

void PracticeScene::Destroy()
{
	for (auto& army : bts)
	{
		army.second->Destroy();
	}
}

void PracticeScene::Input(Event* e)
{
}

void PracticeScene::Update(const sf::Vector2f& mousePosition)
{
	for (auto& army : bts)
	{
		army.second->Update(mousePosition);
	}

	// button�� ������ ���Ӿ����� �̵��ϰԲ�
	/*if (bts["Button!"]->IsPressed())
	{
		scenes->push(new GamingScene(scenes, window, soundSystem));
	}*/
}

void PracticeScene::Update(const float& deltaTime)
{
	if (doll)
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			doll->move({ -3.f,0.f });
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			doll->move({ +3.f,0.f });
		}
		doll->Update(deltaTime);
	}

	if (portal)
	{
		portal->Update(deltaTime);
	}

	// intersects �� contains �� ������ : intersects�� ��ġ�⸸ �ص� ó����, contains�� ��ü�� ��(position)�� ������ ������ ó����

	if (portal && doll) // portal�̶� doll �� �߿� �ϳ���  nullptr�� �ƴҶ�, �� �� �� ������ �ȴ�
	{
		if (portal->getGlobalBounds().contains(doll->getPosition()))
		{
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				// soundSystem->EffectPlay(""); // ������ �Ѿ �� ȿ���� �߰�
				scenes->push(new GamingScene(scenes, window, soundSystem)); // W������ ���Ӿ����� �̵��ϰԲ�
			}
		}
	}
}

void PracticeScene::Render()
{
	for (auto& army : bts)
	{
		army.second->Render(window);
	}
	if (portal)
	{
		portal->Render(window);
	}
	if (doll)
	{
		doll->Render(window);
	}

	// ��Ż�� �Ǹ������� �׸��� ĳ���Ͱ� ���� �׷����⶧���� ��Ż�ڿ� ĳ���Ͱ� �������.
	// ��Ż�� �տ� �׸��� �� ���� ĳ���͸� �׷��ָ�, ĳ���Ͱ� ��Ż ���� �׷��ټ�����
	// ������ ������ �ٲ��൵ ����� ������ �����ϴ�.
}
