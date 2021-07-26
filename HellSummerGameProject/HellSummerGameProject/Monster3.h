#pragma once
#include "AnimationObject.h"

enum MONSTER3_STATE
{
	MONSTER3_IDLE,
	MONSTER3_MOVE_RIGHT,
	MONSTER3_MOVE_LEFT
};

enum MONSTER3_CLASS
{
	MONSTER_MONSTER3
};

class Monster3 : public AnimationObject
{
public:
	Monster3(int monster3Class = MONSTER_MONSTER3);
	Monster3(const Monster3&) = delete;
	Monster3& operator=(const Monster3&) = delete;
	virtual ~Monster3() = default;

protected:
	vector<Texture*> move_rightAnimation;
	vector<Texture*> move_leftAnimation;

	map<int, vector<Texture*>*> stateAnimation;

	float frameTime = 0.2f;
	unsigned keyFrame = 0;
	float speed = 10.f;

	int monster3Class = MONSTER_MONSTER3;
	int monster3State = MONSTER3_IDLE;
	int oldState = MONSTER3_MOVE_RIGHT;

private:
	virtual void Init();

public:
	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Render(RenderTarget* target);
};