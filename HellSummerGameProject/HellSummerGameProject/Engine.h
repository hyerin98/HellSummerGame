#pragma once

class Scene;

//게임 전체를 이르는 클래스
class Engine final // final : 더 이상 이 클래스에게 상속받지 않는다.
{
public: /* 생성자, 소멸자 */
	Engine();
	~Engine();

private: /* 멤버 변수 */
	RenderWindow* window = nullptr;
	Event e;

	Clock timer;
	float deltaTime = 0.f;

	stack<Scene*> scenes;

private: /* 메소드 */
	
	// 엔진을 초기화 하는 함수
	void Init();

	// 윈도우상의 입력값을 처리한다.
	void Input();

	// 현재 살아있는 오브젝트를 업데이트한다.
	void Update();

public:

	// 엔진이 없어지기 전에 호출되는 함수
	void Destroy();

	// 윈도우에 결과물을 출력한다.
	void Render();
};
