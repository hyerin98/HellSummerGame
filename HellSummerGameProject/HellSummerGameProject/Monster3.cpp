//#include "framework.h"
//#include "Monster3.h"
//
//Monster3::Monster3()
//{
//	Init();
//}
//
//Monster3::~Monster3()
//{
//}
//
//void Monster3::Init()
//{
//	Texture* tx = nullptr;
//	char filePath[50];
//	for (int i = 0; i < 12; i++)
//	{
//		sprintf(filePath, "Textures/Monster3/%02d.png", i);
//		tx = new Texture;
//		tx->loadFromFile(filePath);
//		this->vAnimation.push_back(tx);
//	}
//	setScale(Vector2f(0.18f, 0.18f));
//	setPosition(Vector2f(800.f, 260.f));
//}
//
//void Monster3::Destroy()
//{
//	AnimationObject::Destroy();
//}
//
//void Monster3::Update(const float& deltaTime)
//{
//	AnimationObject::Update(deltaTime);;
//}