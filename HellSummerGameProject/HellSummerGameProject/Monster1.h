#pragma once
#include "AnimationObject.h"

class Monster1 : public AnimationObject
{
public:
	Monster1();
	virtual ~Monster1();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};