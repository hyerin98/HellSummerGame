#pragma once
#include "Object.h"
class Bullet :
	public Object
{
public:
	Bullet() = delete;
	Bullet(const string& textureFilePath);
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	virtual ~Bullet() = default; // �Ҹ�� �� �ƹ��� ���̾���, Destroy�� �ֱ⶧���� default

private:
	Vector2f dir{ 0.f, 0.f };
	float speed = 0.f;

	float lifeTime = 4.f; // ����� 1�ʵ��ȸ� ����ְ� �����, �� ���Ŀ��� �������Բ�����

public:
	virtual void Destroy();

	void SetDirection(const Vector2f& dir);
	void SetSpeed(const float& speed);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};
