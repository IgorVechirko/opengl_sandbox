#ifndef Skybox_H
#define Skybox_H

#include "Node.h"
#include "VertexArrayObject.h"
#include "NodeExtensions.h"

namespace GLSandbox
{

	class Skybox
		: public Node
		, public ShaderProtocol
		, public CubeMapProtocol
	{
		
		VertexArrayObject _arrayBuffer;


	public:

		Skybox();
		virtual ~Skybox();
		MAKE_UNCOPYABLE( Skybox );

		bool initWithPlanesPaths( const std::array<std::string,6>& planesPaths );

		void draw();

	};


};


#endif