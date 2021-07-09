#pragma once
#include "AnimationObject.h"

class Monster3 : public AnimationObject
{
public:
	Monster3();
	virtual ~Monster3();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
};
