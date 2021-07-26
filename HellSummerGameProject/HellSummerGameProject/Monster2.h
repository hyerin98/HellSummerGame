#pragma once
#include "AnimationObject.h"

enum MONSTER2_STATE
{
	MONSTER2_IDLE,
	MONSTER2_MOVE_RIGHT,
	MONSTER2_MOVE_LEFT
};

enum MONSTER2_CLASS
{
	MONSTER_MONSTER2
};

class Monster2 : public AnimationObject
{
public:
	Monster2(int monster2Class = MONSTER_MONSTER2);
	Monster2(const Monster2&) = delete;
	Monster2& operator=(const Monster2&) = delete;
	virtual ~Monster2() = default;

protected:
	vector<Texture*> move_rightAnimation;
	vector<Texture*> move_leftAnimation;

	map<int, vector<Texture*>*> stateAnimation;

	float frameTime = 0.2f;
	unsigned keyFrame = 0;
	float speed = 10.f;

	int monster2Class = MONSTER_MONSTER2;
	int monster2State = MONSTER2_IDLE;
	int oldState = MONSTER2_MOVE_RIGHT;

private:
	virtual void Init();

public:
	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Render(RenderTarget* target);
};