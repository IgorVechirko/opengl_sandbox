#ifndef CubeMap_H
#define CubeMap_H

#include "Ref.h"

namespace GLSandbox
{

	class CubeMap : public Ref
	{

		GLuint _textureID;

	public:

		CubeMap();
		virtual ~CubeMap();
		MAKE_UNCOPYABLE( CubeMap );

		bool initWithPlanesPaths( const std::array<std::string,6>& planesPaths );

		void useCubeMap( int samplerIndx = 0 );

	};

}


#endif