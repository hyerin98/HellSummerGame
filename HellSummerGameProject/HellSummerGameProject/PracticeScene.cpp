//#include "framework.h"
//#include "PracticeScene.h"
//#include "Button.h"
//#include "GamingScene.h"
//#include "Character.h"
//
//PracticeScene::PracticeScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem)
//	:Scene(scenes, window, soundSystem)
//{
//	Init();
//}
//
//void PracticeScene::Init()
//{
//
//	bts["Button!"] = new Button("Textures/startbutton1.png","Textures/startbutton2.png", { 200.f,200.f });
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
//}
//
//void PracticeScene::Update(const sf::Vector2f& mousePosition)
//{
//	for (auto& army : bts)
//	{
//		army.second->Update(mousePosition);
//	}
//
//	if (bts["Button!"]->IsPressed())
//	{
//		scenes->push(new GamingScene(scenes, window, soundSystem));
//	}
//}
//
//void PracticeScene::Update(const float& deltaTime)
//{
//}
//
//void PracticeScene::Render()
//{
//	for (auto& army : bts)
//	{
//		army.second->Render(window);
//	}
//	if (doll)
//	{
//		doll->Render(window)
//	}
//	if (potal)
//	{
//		potal
//	}
//}
