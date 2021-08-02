#pragma once
#include "Scene.h"

class Character;
class Monster1;
class Monster2;
class Monster3;
class TileMap;
class BulletManager;

class GamingScene2 : public Scene
{
public:
	GamingScene2() = delete;
	GamingScene2(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	virtual ~GamingScene2() = default;
private:
	Character* character = nullptr;
	Monster1* monster1 = nullptr;
	Monster2* monster2 = nullptr;
	Monster3* monster3 = nullptr;
	BulletManager* bulletMgr = nullptr;
	Object* portal = nullptr;

	TileMap* world = nullptr;
	vector<int> levels;

	View* gameView = nullptr;
	FloatRect viewRect{ 0, 0,  1080, 720 };
	float viewZoomFactor = 1.f;

private:
	virtual void Init();

public:
	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();
};


