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

	stateAnimation.insert({ RUN,runAnimation }); // stateAnimation[RUN] = runAnimation; 이렇게 써도 같은말. 둘 중 편한거로 쓰자
	stateAnimation[ATTACK] = attackAnimation;

	setScale(Vector2f(0.2f, 0.2f));
	setPosition(Vector2f(400.f, 670.f));
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

//void Character::MoveUpdate() // 점프
//{
//	if (position.y < 200.f)
//	{
//		// -10 -> -8 -> -6 ... 
//		velocity.y += gravity;
//	}
//	else if (position.y > 200.f)
//	{
//		// 바닥으로 꺼지는 것을 막기위한 행동
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
	//if (Keyboard::isKeyPressed(Keyboard::Space)) // 점프
	//{
	//	// SFML 좌표계 좌상단이 0, 0
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
		// stateAnimation 이라는 컨테이너 안에 객체 하나씩을 부른다. 이것을 animation
		for (auto& animation : stateAnimation) // stateAnimation 안에 있는 객체들을 animation 하나씩 불러올수있음
		{
			// animation 은 이렇게 되어있음 : <state(first), animationVector(second)> 앞에가 first, 뒤에가 second
			if (animation.first == state) // animation안의 first가 현재상태와 똑같다면
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}