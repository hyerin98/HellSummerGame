#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	MOVE_RIGHT,
	MOVE_LEFT,
	JUMP_RIGHT,
	JUMP_LEFT,
	ATTACK_RIGHT,
	ATTACK_LEFT,
	DIE
};

enum CHARACTER_CLASS
{
	PLAYER_BUBBLUN,
	PLAYER_BOBBLUN
};

class Character : public AnimationObject
{
public:
	Character(int chracterClass = PLAYER_BUBBLUN);
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;
	virtual ~Character() = default;

protected:
	vector<Texture*> move_rightAnimation;
	vector<Texture*> move_leftAnimation;
	vector<Texture*> jump_rightAnimation;
	vector<Texture*> jump_leftAnimation;
	vector<Texture*> attack_rightAnimation;
	vector<Texture*> attack_leftAnimation;
	vector<Texture*> dieAnimation;

	map<int, vector<Texture*>*> stateAnimation;

	float frameTime = 0.2f;
	unsigned int keyFrame = 0;
	float speed = 10.f;

	Vector2f position{ 200.f, 0.f };
	Vector2f velocity{ 0.f, 0.f };
	Vector2f acceleration{ 0.f, 0.f };
	//float speed = 50.f;
	float gravity = 2.f;
	int jumpCount = 2;

	int characterClass = PLAYER_BUBBLUN;
	int characterState = IDLE;
	int oldState = MOVE_RIGHT;

private:
	virtual void Init();

public:
	virtual void Destroy();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Jump();
	virtual void Attack();
	virtual void Render(RenderTarget* target);
	void MoveUpdate(const float& deltaTime);
};