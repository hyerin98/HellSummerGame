#pragma once

class Scene;

//���� ��ü�� �̸��� Ŭ����
class Engine final // final : �� �̻� �� Ŭ�������� ��ӹ��� �ʴ´�.
{
public: /* ������, �Ҹ��� */
	Engine();
	~Engine();

private: /* ��� ���� */
	RenderWindow* window = nullptr;
	Event e;

	Clock timer;
	float deltaTime = 0.f;

	stack<Scene*> scenes;

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
