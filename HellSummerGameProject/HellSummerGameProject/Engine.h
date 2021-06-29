#pragma once
#include <SFML/Graphics.hpp>

// 게임 전체를 이르는 클래스
class Engine final // final은 더 이상 이 클래스에게 상속받지 않는다 라는 뜻
{
public: /* 생성자, 소멸자 를 써주는 편*/

	Engine();
	~Engine();

private: /* 멤버 변수를 써주는 편*/

	RenderWindow* window = nullptr; // 멤버변수 window다 라는 것을 표현하기 위해 m_
	Event evt; // 멤버변수 event다 라는 것을 표현하기 위해 m_

	Clock timer;
	float deltaTime = 0.f; // 이것을 이용해 모든 델타타임을 시간에 맞게 설정

public: /* 메소드를 써주는 편*/

	// 엔진을 초기화 하는 함수
	void Init();


	// 현재 살아있는 오브젝트를 업데이트한다.
	void Update();


	// 윈도우상의 입력값을 처리한다.
	void Input();

public:

	// 엔진이 없어지기 전에 호출되는 함수
	void Destroy();

	// 윈도우에 결과물을 출력한다.
	void Render();

};