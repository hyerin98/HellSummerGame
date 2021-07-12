#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	StartScene(stack <Scene*>* scenes);
	~StartScene();

private:
	Music music;

private:
	virtual void Init();

public:
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

