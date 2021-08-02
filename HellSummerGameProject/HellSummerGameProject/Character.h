#pragma once
#include "AnimationObject.h"

class BulletManager;

enum CHARACTER_STATE
{
	IDLE,
	MOVE_RIGHT,
	MOVE_LEFT,
	JUMP_RIGHT,
	JUMP_LEFT,
	ATTACK_RIGHT,
	ATTACK_LEFT
};

enum CHARACTER_CLASS
{
	PLAYER_BUBBLUN,
	PLAYER_BOBBLUN
};

class Character : public AnimationObject
{
public:
	Character(int characterClass = PLAYER_BUBBLUN);
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;
	virtual ~Character() = default;

protected:

	vector<Texture*> move_rightAnimation;
	vector<Texture*> move_leftAnimation;
	vector<Texture*> attack_rightAnimation;
	vector<Texture*> attack_leftAnimation;
	vector<Texture*> jump_rightAnimation;
	vector<Texture*> jump_leftAnimation;

	Vector2f position{ 450.f, 575.f };
	Vector2f velocity{ 0.f,0.f };
	Vector2f acceleration{ 0.f,0.f };

	map<int, vector<Texture*>*> stateAnimation;

	float frameTime = 0.1f;
	unsigned int keyFrame = 0;
	float speed = 15.f;
	float gravity = 2.f;
	int jumpCount = 2;
	
	int characterClass = PLAYER_BUBBLUN;
	int characterState = MOVE_RIGHT;
	int oldState = IDLE;

private:
	virtual void Init();

	BulletManager* bulletMgr = nullptr;

public:

	virtual void Destroy();

	void Jump();
	void MoveUpdate(const float& deltaTime);
	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
	virtual void Attack();
	virtual void Render(RenderTarget* target);
};