#pragma once
#include "BackgroundObject.h"
#include "Button.h"
#include "TextObject.h"
#include "SoundSystem.h"

class Object;

class Scene
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	virtual ~Scene();

protected:
	// 사운드 추가
	SoundSystem* soundSystem = nullptr;
	// 배경화면
	Object * backGround = nullptr;

	// 애니메이션이 되는 오브젝트 컨테이너
	vector<Object*> animationObjects;

	// 애니메이션이 없는 오브젝트 컨테이너
	vector<Object*> staticObjects;

	// 텍스트 컨테이너
	map<string, TextObject*> mTexts;

	// 버튼 컨테이너
	map<string, Button*> mButtons;

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	// 마우스의 위치 (게임 창 내에서의)
	Vector2f mousePosition{ 0.f, 0.f };

	bool Quit = false;

	//vector<Object*> vObjects;

	//map<string, Text*> mTexts;

	//stack <Scene*>* scenes;

private:
	virtual void Init();

public:
	bool GetQuit();
	void EndScene();
	
	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render();
};
