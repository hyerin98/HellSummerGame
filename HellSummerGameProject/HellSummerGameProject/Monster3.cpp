#include "framework.h"
#include "Monster3.h"

Monster3::Monster3(int monster3Class)
{
	string filePath;
	string fileType = { ".png" };

	switch (monster3Class)
	{
	case MONSTER_MONSTER3:
	{
		filePath = { "Textures/Monster3/" };
		break;
	}
	}

	Texture* texture = nullptr;

	for (int i = 0; i < 6; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_RIGHT0" + to_string(i) + fileType);
		this->move_rightAnimation.push_back(texture);
	}

	for (int i = 0; i < 6; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_LEFT0" + to_string(i) + fileType);
		this->move_leftAnimation.push_back(texture);
	}
	Init();
}

void Monster3::Init()
{
	stateAnimation[MONSTER3_MOVE_RIGHT] = &move_rightAnimation;
	stateAnimation[MONSTER3_MOVE_LEFT] = &move_leftAnimation;

	setTexture(*move_rightAnimation.data()[1]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
	setPosition(800.f, 260.f);
}

void Monster3::Destroy()
{
	AnimationObject::Destroy();
}

void Monster3::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;

	if (elapsedTime >= frameTime)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == monster3State)
			{
				setTexture(*animation.second->data()[keyFrame % animation.second->size()]);
				oldState = animation.first;
			}
			else if (monster3State == MONSTER3_IDLE)
			{
				setTexture(*stateAnimation[oldState]->data()[1]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}

void Monster3::Render(RenderTarget* target)
{
	AnimationObject::Render(target);
}