#pragma once

// ���漱�� -> ��� ���� ���ӹ����� ���� ���� ������ �Ѵ�.
class AnimationObject;

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

	vector<AnimationObject*> obj;

private: /* �޼ҵ� �� ���ִ��� (�������) */

	void Init(); // ������ �ʱ�ȭ�ϴ� �Լ�

	void Update(); // ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.

	void Input(); // ��������� �Է� ���� ó���Ѵ�. 

public:

	void Destroy(); // ������ �������� ���� ȣ��Ǵ� �Լ�

	void Render(); // �����쿡 ������� ����Ѵ�. 
};