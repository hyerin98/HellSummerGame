#pragma once

// 라이브러리를 인클루드 합니다.

// 정규라이브러리를 포함합니다. ex) <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

#define DELETE(x) if(x) delete (x); (x) = nullptr

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <typeinfo>
#include <random>