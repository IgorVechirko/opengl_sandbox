#ifndef Common_H
#define Common_H

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

#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "SOIL/SOIL.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"


#ifndef TEST_FRIEND
	#define TEST_FRIEND
#endif

#define MAKE_UNCOPYABLE(__TYPE__)\
__TYPE__( const __TYPE__& ) = delete;\
__TYPE__( __TYPE__&& ) = delete;\
const __TYPE__& operator= ( const __TYPE__& ) = delete;\
const __TYPE__& operator= ( __TYPE__&& ) = delete;\


namespace GLSandbox
{
	class Console
	{

	public:
	
		static void log()
		{
			std::cout << std::endl;
		}
		template<typename FirstType, typename... Types>
		static void log( const FirstType& firstArg, const Types&... otherArgs )
		{
			std::cout << firstArg;
			log( otherArgs... );
		}
	};


	typedef glm::vec2 Size;
	typedef glm::vec2 Size2;
	typedef glm::vec3 Size3;
	typedef glm::vec2 Vec;
	typedef glm::vec2 Vec2;
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

	
}


#endif