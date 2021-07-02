#pragma once

// protected는 상속받는 클래스끼리만 쓸 수 있다. private은 나 자신에서만 쓸 수있는 것

class Object : public Sprite
{
public:
	Object() = default; // 기본 생성자
	virtual ~Object() = default; // 기본 소멸자

private:

	// 순수 가상 함수
	virtual void Init() = 0; // 왜 virtual void를 쓰냐. 상속받는 놈들의 init은 다를 수 있기 때문에.

public:

	virtual void Destroy() = 0; 
	virtual void Update(const float& deltaTime) = 0;

};

