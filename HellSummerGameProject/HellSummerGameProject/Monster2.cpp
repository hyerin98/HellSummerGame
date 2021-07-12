#include "framework.h"
#include "Monster2.h"

Monster2::Monster2()
{
	Init();
}

Monster2::~Monster2()
{
}

void Monster2::Init()
{
	Texture* tx = nullptr;
	char filePath[50];
	for (int i = 0; i < 4; i++)
	{
		sprintf(filePath, "Textures/Monster2/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setScale(Vector2f(0.18f, 0.18f));
	setPosition(Vector2f(500.f, 160.f));
}

void Monster2::Destroy()
{
	AnimationObject::Destroy();
}

void Monster2::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);;
}
