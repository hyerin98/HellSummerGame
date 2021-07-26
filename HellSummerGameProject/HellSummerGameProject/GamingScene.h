#pragma once
#include "Scene.h"

class Character;
class Monster1;
class Monster2;
class Monster3;
class TileMap;

class GamingScene : public Scene
{
public:
	GamingScene() = delete;
	GamingScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	virtual ~GamingScene() = default;
private:
	Character* character = nullptr;
	Monster1* monster1 = nullptr;
	Monster2* monster2 = nullptr;
	Monster3* monster3 = nullptr;

	// Map Variables

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

