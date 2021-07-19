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
	// ���� �߰�
	SoundSystem* soundSystem = nullptr;
	// ���ȭ��
	Object * backGround = nullptr;

	// �ִϸ��̼��� �Ǵ� ������Ʈ �����̳�
	vector<Object*> animationObjects;

	// �ִϸ��̼��� ���� ������Ʈ �����̳�
	vector<Object*> staticObjects;

	// �ؽ�Ʈ �����̳�
	map<string, TextObject*> mTexts;

	// ��ư �����̳�
	map<string, Button*> mButtons;

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	// ���콺�� ��ġ (���� â ��������)
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
