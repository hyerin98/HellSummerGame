#pragma once
#include <SFML/Graphics.hpp>

// ���� ��ü�� �̸��� Ŭ����
class Engine final // final�� �� �̻� �� Ŭ�������� ��ӹ��� �ʴ´� ��� ��
{
public: /* ������, �Ҹ��� �� ���ִ� ��*/

	Engine();
	~Engine();

private: /* ��� ������ ���ִ� ��*/

	RenderWindow* window = nullptr; // ������� window�� ��� ���� ǥ���ϱ� ���� m_
	Event evt; // ������� event�� ��� ���� ǥ���ϱ� ���� m_

	Clock timer;
	float deltaTime = 0.f; // �̰��� �̿��� ��� ��ŸŸ���� �ð��� �°� ����

public: /* �޼ҵ带 ���ִ� ��*/

	// ������ �ʱ�ȭ �ϴ� �Լ�
	void Init();


	// ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.
	void Update();


	// ��������� �Է°��� ó���Ѵ�.
	void Input();

public:

	// ������ �������� ���� ȣ��Ǵ� �Լ�
	void Destroy();

	// �����쿡 ������� ����Ѵ�.
	void Render();

};