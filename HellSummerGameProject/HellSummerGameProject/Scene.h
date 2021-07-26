#pragma once
#include "Object.h"
#include "ButtonObject.h"
#include "TextObject.h"
#include "SoundSystem.h"

class Object;

class Scene
{
public:
	Scene() = delete;
	Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	Scene(const Scene&) = delete;
	Scene operator=(const Scene&) = delete;
	virtual ~Scene() = default;

protected:
	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;
	SoundSystem* soundSystem = nullptr; // 사운드 추가

	Object * backGround = nullptr; // 배경화면
	vector<Object*> objects; // 애니메이션이 되는 오브젝트 컨테이너
	map<string, ButtonObject*> buttons; // 버튼 컨테이너
	map<string, TextObject*> texts; // 텍스트 컨테이너


	bool Quit = false;

	//vector<Object*> vObjects;

	//map<string, Text*> mTexts;

	//stack <Scene*>* scenes;

	// Vector2f mousePosition{ 0.f, 0.f }; // 마우스의 위치 (게임 창 내에서의)

	// vector<Object*> staticObjects; // 애니메이션이 없는 오브젝트 컨테이너

private:
	virtual void Init();

public:
	void EndScene();
	bool GetQuit();
	
	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const Vector2f& mousePosition);
	virtual void Update(const float& deltaTime);

	virtual void Render();
};
