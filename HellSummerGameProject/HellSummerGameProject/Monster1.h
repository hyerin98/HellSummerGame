#pragma once
#include "AnimationObject.h"

enum MONSTER1_STATE
{
	MONSTER1_IDLE,
	MONSTER1_MOVE_RIGHT,
	MONSTER1_MOVE_LEFT
};

enum MONSTER1_CLASS
{
	MONSTER_MONSTER1
};

class Monster1 : public AnimationObject
{
public:
	Monster1(int monster1Class = MONSTER_MONSTER1);
	Monster1(const Monster1&) = delete;
	Monster1& operator=(const Monster1&) = delete;
	virtual ~Monster1() = default;

protected:
	vector<Texture*> move_rightAnimation;
	vector<Texture*> move_leftAnimation;

	map<int, vector<Texture*>*> stateAnimation;

	float frameTime = 0.2f;
	unsigned keyFrame = 0;
	float speed = 10.f;

	int monster1Class = MONSTER_MONSTER1;
	int monster1State = MONSTER1_IDLE;
	int oldState = MONSTER1_MOVE_RIGHT;

private:
	virtual void Init();

public:
	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Render(RenderTarget* target);
};