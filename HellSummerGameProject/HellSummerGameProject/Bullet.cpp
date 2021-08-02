#include "framework.h"
#include "Bullet.h"

Bullet::Bullet(const string& textureFilePath)
	:Object(textureFilePath)
{
}

void Bullet::Destroy()
{
	Object::Destroy();
}

void Bullet::SetDirection(const Vector2f& dir)
{
	this->dir = dir; // 멤버변수랑 함수 매개변수의 이름이 똑같으면 this 를 이용해서 구분해준다.
}

void Bullet::SetSpeed(const float& speed)
{
	this->speed = speed;

}

void Bullet::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	lifeTime -= deltaTime;

	if (lifeTime <= 0.f)
	{
		SetActive(false);
		lifeTime = 4.f;
	}
	if (isActive)
	{
		move(dir * speed * deltaTime); // 방향으로 속도만큼 움직인다.
	}
}

void Bullet::Update(const Vector2f& mousePosition)
{
}

void Bullet::Render(RenderTarget* target)
{
	Object::Render(target);
}
