#pragma once
#include "SoundSystem.h"

class Scene;

//���� ��ü�� �̸��� Ŭ����
class Engine final // final : �� �̻� �� Ŭ�������� ��ӹ��� �ʴ´�.
{
public: /* ������, �Ҹ��� */
	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	~Engine();

private: /* ��� ���� */
	RenderWindow* window = nullptr;

	stack<Scene*> scenes;
	SoundSystem* soundSystem = nullptr;
	Event* e = nullptr;

	Clock* timer = nullptr;
	float deltaTime = 0.f;
	float elapsedTime = 0.f;


private: /* �޼ҵ� */
	
	// ������ �ʱ�ȭ �ϴ� �Լ�
	void Init();

	// ��������� �Է°��� ó���Ѵ�.
	void Input();

	// ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.
	void Update();

public:

	// ������ �������� ���� ȣ��Ǵ� �Լ�
	void Destroy();

	// �����쿡 ������� ����Ѵ�.
	void Render();
};
