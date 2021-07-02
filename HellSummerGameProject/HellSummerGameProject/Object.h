#pragma once

// protected�� ��ӹ޴� Ŭ���������� �� �� �ִ�. private�� �� �ڽſ����� �� ���ִ� ��

class Object : public Sprite
{
public:
	Object() = default; // �⺻ ������
	virtual ~Object() = default; // �⺻ �Ҹ���

private:

	// ���� ���� �Լ�
	virtual void Init() = 0; // �� virtual void�� ����. ��ӹ޴� ����� init�� �ٸ� �� �ֱ� ������.

public:

	virtual void Destroy() = 0; 
	virtual void Update(const float& deltaTime) = 0;

};

