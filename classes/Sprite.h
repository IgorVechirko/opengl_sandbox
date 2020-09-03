#ifndef Sprite_H
#define Sprite_H


#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayObject.h"

namespace GLSandbox
{
	class Sprite 
		: public Node
		, public ShaderProtocol
		, public Texture2DProtocol
			
	{
		typedef Node Parent;

		VertexArrayObject _arrayBuffer;


	public:

		Sprite();
		virtual ~Sprite();
		MAKE_UNCOPYABLE(Sprite);

		bool initWithFilePath( const std::string& filePath );

		virtual void draw( const Mat4& transform ) override;

		virtual void setTexture2D( Texture2D* texture ) override;

	};


}


#endif