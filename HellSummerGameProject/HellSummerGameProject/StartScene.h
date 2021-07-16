#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	StartScene(stack<Scene*>* scenes, RenderWindow* window);
	~StartScene();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};

