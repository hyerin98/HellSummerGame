#include "framework.h"
#include "Character.h"

Character::Character()
{
	Init();
}

Character::~Character()
{
}

void Character::Init()
{
	Texture* tx = nullptr;
	char filePath[50];
	for (int i = 0; i < 6; i++)
	{
		sprintf(filePath, "Textures/runright/%02d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->runrightAnimation.push_back(tx);
	}

	for (int i = 0; i < 5; i++)
	{
		sprintf(filePath, "Textures/runleft/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->runleftAnimation.push_back(tx);
	}

	for (int i = 0; i < 4; i++)
	{
		sprintf(filePath, "Textures/attackright/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->attackrightAnimation.push_back(tx);
	}

	for (int i = 0; i < 4; i++)
	{
		sprintf(filePath, "Textures/attackleft/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->attackleftAnimation.push_back(tx);
	}


	stateAnimation.insert({ RUNRIGHT,runrightAnimation }); // stateAnimation[RUN] = runAnimation; �̷��� �ᵵ ������. �� �� ���Ѱŷ� ����
	stateAnimation[RUNLEFT] = runleftAnimation;
	stateAnimation[ATTACKRIGHT] = attackrightAnimation;
	stateAnimation[ATTACKLEFT] = attackleftAnimation;

	setScale(Vector2f(0.2f, 0.2f));
	setPosition(Vector2f(400.f, 670.f));
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

//void Character::MoveUpdate() // ����
//{
//	if (position.y < 200.f)
//	{
//		// -10 -> -8 -> -6 ... 
//		velocity.y += gravity;
//	}
//	else if (position.y > 200.f)
//	{
//		// �ٴ����� ������ ���� �������� �ൿ
//		position.y = 200.f;
//	}
//
//	velocity += acceleration;
//
//	position += velocity;
//
//	setPosition(position);
//}

void Character::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		state = RUNRIGHT;
		move(0.08f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			state = ATTACKRIGHT;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		state = RUNLEFT;
		move(-0.08f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			state = ATTACKLEFT;
		}
	}

	//if (Keyboard::isKeyPressed(Keyboard::Space)) // ����
	//{
	//	// SFML ��ǥ�� �»���� 0, 0
	//	velocity.y = -1.0f;
	//}
	//MoveUpdate();

	elapsedTime += deltaTime;

	if (elapsedTime > 0.13f)
	{
		// stateAnimation �̶�� �����̳� �ȿ� ��ü �ϳ����� �θ���. �̰��� animation
		for (auto& animation : stateAnimation) // stateAnimation �ȿ� �ִ� ��ü���� animation �ϳ��� �ҷ��ü�����
		{
			// animation �� �̷��� �Ǿ����� : <state(first), animationVector(second)> �տ��� first, �ڿ��� second
			if (animation.first == state) // animation���� first�� ������¿� �Ȱ��ٸ�
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}