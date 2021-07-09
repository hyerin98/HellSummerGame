#pragma once
#include "AnimationObject.h"

class Monster2 : public AnimationObject
{
public:
	Monster2();
	virtual ~Monster2();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};