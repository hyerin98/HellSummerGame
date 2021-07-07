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
	for (int i = 0; i < 1; i++)
	{
		sprintf(filePath, "Textures/run/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->runAnimation.push_back(tx);
	}

	for (int i = 0; i < 1; i++)
	{
		sprintf(filePath, "Textures/attack/%02d.png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->attackAnimation.push_back(tx);
	}

	stateAnimation.insert({ RUN,runAnimation }); // stateAnimation[RUN] = runAnimation; �̷��� �ᵵ ������. �� �� ���Ѱŷ� ����
	stateAnimation[ATTACK] = attackAnimation;

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
	//if (Keyboard::isKeyPressed(Keyboard::Space)) // ����
	//{
	//	// SFML ��ǥ�� �»���� 0, 0
	//	velocity.y = -2.5f;
	//}
	//MoveUpdate();

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		state = RUN;
	}
	
	else if (Keyboard::isKeyPressed(Keyboard::X))
	{
		state = ATTACK;
	}

	elapsedTime += deltaTime;

	if (elapsedTime > 0.2f)
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