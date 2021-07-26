#pragma once

// 라이브러리를 인클루드 합니다.

// 정규라이브러리를 포함합니다. ex) <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

#define DELETE(x) if(x) delete (x); (x) = nullptr;
constexpr float PI = 3.14159265f;

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <typeinfo>
#include <random>
#include <fstream>

namespace Math
{
	// 이 안에 있는 함수의 Math::Function();

	inline const Vector2f Normalize(const Vector2f& vec1, const Vector2f& vec2)
	{
		Vector2f direction;
		direction.x = vec1.x - vec2.x;
		direction.y = vec1.y - vec2.y;
	}
}