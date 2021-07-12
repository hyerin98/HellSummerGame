#include "framework.h"
#include "PassPoint.h"

PassPoint::PassPoint()
{
	Init();
}

PassPoint::~PassPoint()
{
}

void PassPoint::Init()
{
	Texture* tx = nullptr;
	char filePath[50];
	for (int i = 0; i < 9; i++)
	{
		sprintf(filePath, "Textures/PassPoint/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setScale(Vector2f(0.2f, 0.2f));
	setPosition(Vector2f(1020.f, 560.f));


}

void PassPoint::Destroy()
{
	AnimationObject::Destroy();
}

void PassPoint::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);;
}
