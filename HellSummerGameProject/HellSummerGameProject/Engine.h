#pragma once

// ���� ��ü�� �̸��� Ŭ����
class Engine final // final : �� �̻� �� Ŭ�������� ��ӹ��� �ʴ´�.
{
public : /* ������, �Ҹ��� �� ���ִ��� (�������) */

	Engine();
	~Engine();

private: /* ��� ���� �� ���ִ��� (�������) */


	RenderWindow* window = nullptr;
	Event e;

	Clock timer;
	float deltaTime = 0.f;

public: /* �޼ҵ� �� ���ִ��� (�������) */

	void Init(); // ������ �ʱ�ȭ�ϴ� �Լ�

	void Destroy(); // ������ �������� ���� ȣ��Ǵ� �Լ�

	void Input(); // ��������� �Է� ���� ó���Ѵ�. 

	void Update(); // ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.

	void Render(); // �����쿡 ������� ����Ѵ�. 
};