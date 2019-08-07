#ifndef VECommon_H
#define VECommon_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <array>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>

#include <rapidjson.h>
#include <document.h>

#include "glm.hpp"

// GLEW
#define GLEW_STATIC
#include <glew.h>

// GLFW
#include <glfw3.h>

#define _VESTART namespace VEngine {

#define _VEEND }

#define _USEVE using namespace::VEngine;


_VESTART

typedef glm::vec2 Size;
typedef glm::vec2 Vec;

struct RGBA
{
	float _r;
	float _g;
	float _b;
	float _a;

	RGBA()
		: _r(0.0f)
		, _g(0.0f)
		, _b(0.0f)
		, _a(0.0f)
	{};

	RGBA(float r, float g, float b, float a = 1.0f )
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	};

	static const RGBA WHITE;
	static const RGBA RED;
	static const RGBA BLACK;
	static const RGBA GREEN;
};

struct Vertex
{
	Vec _pos;
	RGBA _color;

	Vertex()
	{};

	Vertex( const Vec& pos, const RGBA& color )
	{
		_pos = pos;
		_color = color; 
	}
};

_VEEND


#endif