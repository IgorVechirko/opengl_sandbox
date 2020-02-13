#ifndef VECommon_H
#define VECommon_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
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
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

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
typedef glm::vec3 Size3;
typedef glm::vec2 Vec;
typedef glm::vec3 Vec3;
typedef glm::mat4 Mat4;

struct RGBA : glm::vec4
{
	RGBA()
	{};

	RGBA(float r, float g, float b, float a )
		: glm::vec4( r, g, b, a )
	{
	};

	static const RGBA WHITE;
	static const RGBA RED;
	static const RGBA BLACK;
	static const RGBA GREEN;
};

struct PosVertex
{
	Vec3 pos;
};

struct PosNormaTextCordVertex
{
	Vec3 pos;
	Vec3 normal;
	glm::vec2 textCord;
};

enum class eTextureType
{
	NONE,
	DIFFUSE_LIHGT_MAP,
	SPECULAR_LIHGT_MAP
};

struct Texture
{
	GLint id;
	eTextureType type;

	Texture()
		: id( 0 )
		, type( eTextureType::NONE )
	{
	}
};

struct Material 
{
	Vec3 ambient;
	Vec3 diffuse;
	Vec3 specular;
	float shininess;

	Material()
		: shininess( 0.0f )
		, ambient( 1.0f, 1.0f, 1.0f )
		, diffuse( 1.0f, 1.0f, 1.0f )
		, specular( 1.0f, 1.0f, 1.0f )
	{};
};

struct LightProperties
{
	Vec3 ambient;
	Vec3 diffuse;
	Vec3 specular;

	LightProperties()
		: ambient( 0.0f, 0.0f, 0.0f )
		, diffuse( 0.0f, 0.0f, 0.0f )
		, specular( 0.0f, 0.0f, 0.0f )
	{
	};
};

struct LightAttenuationCoefs
{
	float constant;
	float linear;
	float quadratic;

	LightAttenuationCoefs()
		: constant( 1.0f )
		, linear( 0.0f )
		, quadratic( 0.0f )
	{};
};

#define DEF_WIN_SIZE Size( 1024, 768 )
#define LOG( __FORMAT__, ... ) printf( __FORMAT__, __VA_ARGS__ );\
							   printf( "\n" );
#define AUTORELEASE_CREATE_FUNC(__TYPE__)\
static __TYPE__* create()\
{\
__TYPE__* ret = new __TYPE__();\
if ( ret && ret->init() )\
{\
	ret->autorelease();\
}\
else\
{\
delete ret;\
ret = nullptr;\
}\
return ret;\
}\

_VEEND


#endif