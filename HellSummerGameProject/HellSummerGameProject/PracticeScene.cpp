//#include "framework.h"
//#include "PracticeScene.h"
//#include "Button.h"
//#include "GamingScene.h"
//#include "JumpObject.h"
//
//PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
//	:Scene(scenes, window, soundSystem)
//{
//	Init();
//}
//
//void PracticeScene::Init()
//{
//	bts["Button!"] = new Button("Textures/startbutton1.png","Textures/startbutton2.png", { 200.f,200.f });
//	
//	doll = new JumpObject("Textures/test.png", {500.f, 500.f});
//	portal = new Object("Textures/04.png");
//
//	// doll->setPosition(500.f, 500.f);
//	portal->setPosition(50.f, 500.f);
//	
//}
//
//void PracticeScene::Destroy()
//{
//	for (auto& army : bts)
//	{
//		army.second->Destroy();
//	}
//}
//
//void PracticeScene::Input(Event* e)
//{
//	switch (e->type)
//	{
//	case Event::KeyPressed:
//	{
//		switch (e->key.code)
//		{
//			case Keyboard::Space:
//			{
//				// Down Casting을 해주자
//				dynamic_cast<JumpObject*>(doll)->Jump();
//				break;
//			}
//			default:
//				break;
//		}
//		break;
//	}
//
//	case Event::MouseButtonPressed:
//	{
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//void PracticeScene::Update(const sf::Vector2f& mousePosition)
//{
//	for (auto& army : bts)
//	{
//		army.second->Update(mousePosition);
//	}
//
//	// button을 누르면 게임씬으로 이동하게끔
//	/*if (bts["Button!"]->IsPressed())
//	{
//		scenes->push(new GamingScene(scenes, window, soundSystem));
//	}*/
//}
//
//void PracticeScene::Update(const float& deltaTime)
//{
//	if (doll)
//	{
//		doll->Update(deltaTime);
//	}
//
//	if (portal)
//	{
//		portal->Update(deltaTime);
//	}
//
//	// intersects 와 contains 와 차이점 : intersects는 겹치기만 해도 처리함, contains은 물체의 점(position)이 안으로 들어갔을때 처리됨
//
//	if (portal && doll) // portal이랑 doll 둘 중에 하나가  nullptr가 아닐때, 두 개 다 있을때 된다
//	{
//		if (portal->getGlobalBounds().contains(doll->getPosition()))
//		{
//			if (Keyboard::isKeyPressed(Keyboard::W))
//			{
//				// soundSystem->EffectPlay(""); // 씬으로 넘어갈 때 효과음 추가
//				scenes->push(new GamingScene(scenes, window, soundSystem)); // W누르면 게임씬으로 이동하게끔
//			}
//		}
//	}
//}
//
//void PracticeScene::Render()
//{
//	for (auto& army : bts)
//	{
//		army.second->Render(window);
//	}
//	if (portal)
//	{
//		portal->Render(window);
//	}
//	if (doll)
//	{
//		doll->Render(window);
//	}
//
//	// 포탈을 맨마지막에 그리면 캐릭터가 먼저 그려졌기때문에 포탈뒤에 캐릭터가 숨어버림.
//	// 포탈을 앞에 그리고 그 다음 캐릭터를 그려주면, 캐릭터가 포탈 위에 그려줄수있음
//	// 랜더링 순서만 바꿔줘도 충분히 수정이 가능하다.
//}
