#include "framework.h"
#include "Character.h"
#define FLOOR_Y 575.f

Character::Character(int chracterClass)
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
		filePath={"Textures/"}
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

	Init();
}

void Character::Init()
{
	stateAnimation[MOVE_RIGHT] = &move_rightAnimation;
	stateAnimation[MOVE_LEFT] = &move_leftAnimation;
	stateAnimation[JUMP_RIGHT] = &jump_rightAnimation;
	stateAnimation[JUMP_LEFT] = &jump_leftAnimation;
	stateAnimation[ATTACK_RIGHT] = &attack_rightAnimation;
	stateAnimation[ATTACK_LEFT] = &attack_leftAnimation;

	setTexture(*move_rightAnimation.data()[1]);
	setOrigin(Vector2f(getGlobalBounds().width / 2.f, getGlobalBounds().height));
	//setScale(Vector2f(0.2f, 0.2f));
	setPosition(Vector2f(450.f, 575.f));
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::MoveUpdate(const float& deltaTime)
{
	if (position.y < FLOOR_Y)
	{
		// -10 -> -8 -> -6 ... 
		// 위로 점프하기 위한 행동
		velocity.y += gravity * speed * deltaTime;
	}
	else if (position.y > FLOOR_Y)
	{
		// 바닥으로 꺼지는 것을 막기위한 행동
		position.y = FLOOR_Y;
	}

	velocity += acceleration * speed * deltaTime;

	position += velocity;

	setPosition(position);
}

void Character::Jump()
{
	if (--jumpCount > 0)
	{
		velocity.y = -20.f;
	}
}


void Character::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
	MoveUpdate(deltaTime);
	static int count = 0;

	static float elapsedTime = 0;
	elapsedTime += deltaTime;



	if (position.y < FLOOR_Y - 30.f)
	{
		characterState = JUMP_RIGHT;
		characterState = JUMP_LEFT;
	}
	else
	{
		jumpCount = 2;
	}
	cout << "JumpCount = " << jumpCount << endl;

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		characterState = MOVE_RIGHT;
		move({ 1.f, 0.f });

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			characterState = ATTACK_RIGHT;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		characterState = MOVE_LEFT;
		move(-1.0f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			characterState = ATTACK_LEFT;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && Keyboard::isKeyPressed(Keyboard::Right))
	{
		characterState = JUMP_RIGHT;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && Keyboard::isKeyPressed(Keyboard::Left))
	{
		characterState = JUMP_LEFT;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && jumpCount !=2)
	{
		characterState = JUMP_RIGHT;
	}

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

void Character::Update(const Vector2f& mousePosition)
{
	AnimationObject::Update(mousePosition);
}

void Character::Attack()
{
}

void Character::Render(RenderTarget* target)
{
}
