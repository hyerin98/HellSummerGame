#pragma once
#include "Scene.h"
class CharacterScene : public Scene
{
public:
	CharacterScene();
	CharacterScene(stack<Scene*>* scenes, RenderWindow* window);
	virtual ~CharacterScene();

private:
	virtual void Init();

public:
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};
