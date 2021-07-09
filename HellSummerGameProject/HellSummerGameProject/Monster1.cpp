#include "framework.h"
#include "Monster1.h"

Monster1::Monster1()
{
	Init();
}

Monster1::~Monster1()
{
}

void Monster1::Init()
{
	Texture* tx = nullptr;
	char filePath[50];
	for (int i = 0; i < 8; i++)
	{
		sprintf(filePath, "Textures/Monster1/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setScale(Vector2f(0.18f, 0.18f));
	setPosition(Vector2f(300.f, 540.f));
}

void Monster1::Destroy()
{
	AnimationObject::Destroy();
}

void Monster1::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);;
}