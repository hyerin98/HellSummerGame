#pragma once
#include "Scene.h"

class Button;

class PracticeScene : public Scene
{
public:
	PracticeScene() = delete;
	PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	PracticeScene(const PracticeScene&) = delete;
	PracticeScene& operator=(const PracticeScene&) = delete;
	virtual ~PracticeScene() = default;
	
private:
	map<string, Button*> bts;
	Object* doll = nullptr;
	Object* potal = nullptr;

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const sf::Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};
