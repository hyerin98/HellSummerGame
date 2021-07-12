#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	// IDLE
	RUNRIGHT,
	RUNLEFT,
	ATTACKRIGHT,
	ATTACKLEFT
};

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:
	virtual void Init();

	Vector2f position{ 0.f,0.f };
	Vector2f velocity{ 0.f,0.f };
	Vector2f acceleration{ 0.f,0.f };

	float gravity = 2.f;

	vector<Texture*> runrightAnimation;
	vector<Texture*> runleftAnimation;
	vector<Texture*> attackrightAnimation;
	vector<Texture*> attackleftAnimation;

	int state = RUNRIGHT;

	map<int, vector<Texture*>> stateAnimation; // int 자료형 하나랑 vector를 짝꿍시켜준것
											   // 예를 들어서, run을(key) 부르면 run이랑 runAnimation(value)을 짝꿍시켜주고,
											   // attack을 부르면 attack이랑 attackAnimataion을 짝꿍시켜주는 것
											   // key는 first라고도 불리고, value는 second라고도 불림 

public:
	virtual void Destroy();

	void MoveUpdate();
	virtual void Update(const float& deltaTime);
};