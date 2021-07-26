#include "framework.h"
#include "Monster1.h"

Monster1::Monster1(int monster1Class)
{
	string filePath;
	string fileType = { ".png" };

	switch (monster1Class)
	{
	case MONSTER_MONSTER1:
	{
		filePath = { "Textures/Monster1/" };
		break;
	}
	}

	Texture* texture = nullptr;

	for (int i = 0; i < 4; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_RIGHT0" + to_string(i) + fileType);
		this->move_rightAnimation.push_back(texture);
	}

	for (int i = 0; i < 4; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_LEFT0" + to_string(i) + fileType);
		this->move_leftAnimation.push_back(texture);
	}
	Init();
}

void Monster1::Init()
{
	stateAnimation[MONSTER1_MOVE_RIGHT] = &move_rightAnimation;
	stateAnimation[MONSTER1_MOVE_LEFT] = &move_leftAnimation;

	setTexture(*move_rightAnimation.data()[0]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
	setPosition(350.f, 360.f);
}

void Monster1::Destroy()
{
	AnimationObject::Destroy();
}

void Monster1::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	/*static float elapsedTime = 0.f;

	if (elapsedTime >= frameTime)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == monster1State)
			{
				setTexture(*animation.second->data()[keyFrame % animation.second->size()]);
				oldState = animation.first;
			}
			else if (monster1State == MONSTER1_IDLE)
			{
				setTexture(*stateAnimation[oldState]->data()[1]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}*/
}

void Monster1::Render(RenderTarget* target)
{
	AnimationObject::Render(target);
}