#include "framework.h"
#include "Engine.h"

int main()
{
	Engine engine;

	engine.Render();

	engine.Destroy(); // 윈도우가 동적할당이 됐고, 동적할당을 풀어줘야함.
}