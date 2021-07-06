#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	StartScene(stack <Scene*>* scenes);
	~StartScene();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};

