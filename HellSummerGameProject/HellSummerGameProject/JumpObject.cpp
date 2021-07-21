#include "framework.h"
#include "JumpObject.h"

JumpObject::JumpObject()
{
}

JumpObject::JumpObject(const string& textureFilePath)
	:Object(textureFilePath) // 부모 클래스에게 기본 생성자가 없을 때, 너는 이것을 따라라~ 너도 나처럼 똑같이 만들어야해~ 라는 뜻임
						   // 똑같이 오브젝트를 받을 때, textureFilePath로 받는 생성자가 있었다면, 오브젝트에서도 똑같이 해줄수있다는 뜻(똑같은 기능)
{
}

JumpObject::JumpObject(const string& textureFilePath, const Vector2f& position)
	: Object(textureFilePath, position)
{
	this->position = position;
}

void JumpObject::Destroy()
{
}

void JumpObject::JumpUpdate(const float& deltaTime)
{
	if (position.y < 500.f) // 점프 좌표 갱신
	{
		velocity.y += gravity * speed * deltaTime;
	}
	else if(position.y > 500.f) // 바닥으로 꺼지는 것을 방지하기 위함
	{
		position.y = 500.f;
	}
	velocity += accelation * speed * deltaTime;
	position += velocity;

	//setPosition(position);
}

void JumpObject::Jump()
{
	velocity.y = -20.f;
}

void JumpObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	JumpUpdate(deltaTime);

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		position.x -= 3.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		position.x += 3.f;
	}
	setPosition(position);
}

void JumpObject::Update(const Vector2f& mousePosition)
{
}

void JumpObject::Render(RenderTarget* target)
{
	Object::Render(target);
}
