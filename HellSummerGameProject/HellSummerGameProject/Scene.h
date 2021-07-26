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
	SoundSystem* soundSystem = nullptr; // ���� �߰�

	Object * backGround = nullptr; // ���ȭ��
	vector<Object*> objects; // �ִϸ��̼��� �Ǵ� ������Ʈ �����̳�
	map<string, ButtonObject*> buttons; // ��ư �����̳�
	map<string, TextObject*> texts; // �ؽ�Ʈ �����̳�


	bool Quit = false;

	//vector<Object*> vObjects;

	//map<string, Text*> mTexts;

	//stack <Scene*>* scenes;

	// Vector2f mousePosition{ 0.f, 0.f }; // ���콺�� ��ġ (���� â ��������)

	// vector<Object*> staticObjects; // �ִϸ��̼��� ���� ������Ʈ �����̳�

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
