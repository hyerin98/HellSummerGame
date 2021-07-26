#include "framework.h"
#include "Monster2.h"

Monster2::Monster2(int monster2Class)
{
	string filePath;
	string fileType = { ".png" };

	switch (monster2Class)
	{
	case MONSTER_MONSTER2:
	{
		filePath = { "Textures/Monster2/" };
		break;
	}
	}

	Texture* texture = nullptr;

	for (int i = 0; i < 2; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_RIGHT0" + to_string(i) + fileType);
		this->move_rightAnimation.push_back(texture);
	}

	for (int i = 0; i < 2; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_LEFT0" + to_string(i) + fileType);
		this->move_leftAnimation.push_back(texture);
	}
	Init();
}

void Monster2::Init()
{
	stateAnimation[MONSTER2_MOVE_RIGHT] = &move_rightAnimation;
	stateAnimation[MONSTER2_MOVE_LEFT] = &move_leftAnimation;

	setTexture(*move_rightAnimation.data()[1]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
	setPosition(500.f, 160.f);
}

void Monster2::Destroy()
{
	AnimationObject::Destroy();
}

void Monster2::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;

	if (elapsedTime >= frameTime)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == monster2State)
			{
				setTexture(*animation.second->data()[keyFrame % animation.second->size()]);
				oldState = animation.first;
			}
			else if (monster2State == MONSTER2_IDLE)
			{
				setTexture(*stateAnimation[oldState]->data()[1]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}

void Monster2::Render(RenderTarget* target)
{
	AnimationObject::Render(target);
}