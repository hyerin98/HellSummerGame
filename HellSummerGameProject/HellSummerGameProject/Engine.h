#pragma once
#include "Scene.h"

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
	SoundSystem* soundSystem = nullptr;
	stack<Scene*> scenes;

	Event* e = nullptr;
	Vector2f mousePosition{ 0.f, 0.f };

	Clock* clock = nullptr;
	float deltaTime = 0.f;
	float elapsedTime = 0.f;


private: /* �޼ҵ� */
	
	// ������ �ʱ�ȭ �ϴ� �Լ�
	void Init();

	// ������ �������� ���� ȣ��Ǵ� �Լ�
	void Destroy();

	// ��������� �Է°��� ó���Ѵ�.
	void Input();

	// ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.
	void Update();

public:

	// �����쿡 ������� ����Ѵ�.
	bool Render();
};
