#ifndef Sprite_H
#define Sprite_H


#include "Node.h"
#include "NodeExtensions.h"
#include "VertexArrayBuffer.h"

namespace GLSandbox
{
	class Sprite 
		: public Node
		, public ShaderProtocol
		, public Texture2DProtocol
			
	{
		typedef Node Parent;

		VertexArrayBuffer _arrayBuffer;


	protected:

		virtual void draw( GLRender* render, const Mat4& transform ) override;

	public:

		Sprite();
		virtual ~Sprite();
		MAKE_UNCOPYABLE(Sprite);

		bool initWithFilePath( const std::string& filePath );

		virtual void setTexture2D( Texture2D* texture ) override;

	};


}


#endif