#include "framework.h"
#include "Character.h"

Character::Character(int characterClass)
{
	string filePath;
	string fileType = { ".png" };

	switch (characterClass)
	{
	case PLAYER_BUBBLUN:
	{
		filePath = { "Textures/Player_Bubblun/" };
		break;
	}
	/*case PLAYER_BOBBLUN:
	{
	}*/
	}

	Texture* texture = nullptr;

	for (int i = 0; i < 6; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_RIGHT0" + to_string(i) + fileType);
		this->move_rightAnimation.push_back(texture);
	}
		
	for (int i = 0; i < 5; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "MOVE_LEFT0" + to_string(i) + fileType);
		this->move_leftAnimation.push_back(texture);
	}

	for (int i = 0; i < 4; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "ATTACK_RIGHT0" + to_string(i) + fileType);
		this->attack_rightAnimation.push_back(texture);
	}
		
	for (int i = 0; i < 4; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "ATTACK_LEFT0" + to_string(i) + fileType);
		this->attack_leftAnimation.push_back(texture);
	}


	for (int i = 0; i < 8; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "JUMP_RIGHT0" + to_string(i) + fileType);
		this->jump_rightAnimation.push_back(texture);
	}


	for (int i = 0; i < 8; i++)
	{
		texture = new Texture;
		texture->loadFromFile(filePath + "JUMP_LEFT0" + to_string(i) + fileType);
		this->jump_leftAnimation.push_back(texture);
	}

	Init();
}

void Character::Init()
{

	stateAnimation[MOVE_RIGHT] = &move_rightAnimation;
	stateAnimation[MOVE_LEFT] = &move_leftAnimation;
	stateAnimation[ATTACK_RIGHT] = &attack_rightAnimation;
	stateAnimation[ATTACK_LEFT] = &attack_leftAnimation;
	stateAnimation[JUMP_RIGHT] = &jump_rightAnimation;
	stateAnimation[JUMP_LEFT] = &jump_leftAnimation;

	setTexture(*move_rightAnimation.data()[1]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
	setPosition(450.f, 575.f);
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;
	MoveUpdate(deltaTime);

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		characterState = JUMP_RIGHT;
		Jump();
		cout << "jump" << endl;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		characterState = MOVE_RIGHT;
		position += {2.f, 0.f};

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			characterState = ATTACK_RIGHT;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		characterState = MOVE_LEFT;
		position -= {2.f, 0.f};

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			characterState = ATTACK_LEFT;
		}
	}

	/*else
	{
		characterState = IDLE;
	}*/

	if (elapsedTime >= frameTime)
	{
		for (auto& animation : stateAnimation)
		{
			if (animation.first == characterState)
			{
				setTexture(*animation.second->data()[keyFrame % animation.second->size()]);
				oldState = animation.first;
			}
			else if (characterState == IDLE)
			{
				setTexture(*stateAnimation[oldState]->data()[1]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}

void Character::Jump()
{
	velocity.y = -10.f;
}

void Character::MoveUpdate(const float& deltaTime)
{
	if (position.y < 575.f)
	{
		velocity.y += gravity * speed * deltaTime;
	}
	else if (position.y > 575)
	{
		position.y = 575;
	}

	velocity += acceleration * speed * deltaTime;

	position += velocity;

	setPosition(position);

}

void Character::Update(const Vector2f& mousePosition)
{
	AnimationObject::Update(mousePosition);

	
}

void Character::Attack()
{
}

void Character::Render(RenderTarget* target)
{
	AnimationObject::Render(target);
}

