#include "framework.h"
#include "Engine.h"

int main()
{
	Engine engine;

	engine.Render();

	engine.Destroy(); // �����찡 �����Ҵ��� �ư�, �����Ҵ��� Ǯ�������.
}