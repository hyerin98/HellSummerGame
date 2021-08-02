#pragma once
#include "Object.h"
class Bullet :
	public Object
{
public:
	Bullet() = delete;
	Bullet(const string& textureFilePath);
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	virtual ~Bullet() = default; // 소멸될 때 아무런 일이없고, Destroy만 있기때문에 default

private:
	Vector2f dir{ 0.f, 0.f };
	float speed = 0.f;

	float lifeTime = 4.f; // 쏘고나서 1초동안만 살아있게 만들고, 그 이후에는 꺼버리게끔하자

public:
	virtual void Destroy();

	void SetDirection(const Vector2f& dir);
	void SetSpeed(const float& speed);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};
