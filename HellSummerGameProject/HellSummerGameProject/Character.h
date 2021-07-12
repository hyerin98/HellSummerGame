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

	map<int, vector<Texture*>> stateAnimation; // int �ڷ��� �ϳ��� vector�� ¦������ذ�
											   // ���� ��, run��(key) �θ��� run�̶� runAnimation(value)�� ¦������ְ�,
											   // attack�� �θ��� attack�̶� attackAnimataion�� ¦������ִ� ��
											   // key�� first��� �Ҹ���, value�� second��� �Ҹ� 

public:
	virtual void Destroy();

	void MoveUpdate();
	virtual void Update(const float& deltaTime);
};