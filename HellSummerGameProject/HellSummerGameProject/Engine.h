#pragma once

// 전방선언 -> 헤더 파일 꼬임방지를 위해 전방 선언을 한다.
class AnimationObject;

// 게임 전체를 이르는 클래스
class Engine final // final : 더 이상 이 클래스에게 상속받지 않는다.
{
public : /* 생성자, 소멸자 를 써주는편 (상관없음) */

	Engine();
	~Engine();

private: /* 멤버 변수 를 써주는편 (상관없음) */


	RenderWindow* window = nullptr;
	Event e;

	Clock timer;
	float deltaTime = 0.f;

	vector<AnimationObject*> obj;

private: /* 메소드 를 써주는편 (상관없음) */

	void Init(); // 엔진을 초기화하는 함수

	void Update(); // 현재 살아있는 오브젝트를 업데이트한다.

	void Input(); // 윈도우상의 입력 값을 처리한다. 

public:

	void Destroy(); // 엔진이 없어지기 전에 호출되는 함수

	void Render(); // 윈도우에 결과물을 출력한다. 
};