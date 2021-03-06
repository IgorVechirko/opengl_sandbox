#include "Cube.h"

#include "ShaderProgram.h"
#include "Scene.h"
#include "GLContext.h"
#include "ShadersCache.h"


namespace GLSandbox
{

	Cube::Cube()
		: _cubeSize( 1.0f )
		, _verticesDirty( true )
	{
	}
	Cube::~Cube()
	{
	}


	bool Cube::onInit()
	{	
		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );

		_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*6, (GLvoid*)0 );
		_arrayBuffer.setupAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*6, (GLvoid*)(3*sizeof(GLfloat)) );

		setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::POS_NORMAL_LIGHT_PROP ) );

		return true;
	}
	void Cube::draw( const Mat4& transform )
	{
		glEnable( GL_CULL_FACE );

		if ( _verticesDirty )
		{
			updateVetices();
			_verticesDirty = false;
		}

		if( _shader )
		{
			_shader->useProgram();
			auto scene = getGLContext()->getScene();

			_shader->setMaterialUniforms( getMaterial(), "u_material", "ambient", "diffuse", "specular", "shininess" );

			scene->setProjectionToShader( _shader );
			scene->setViewToShader( _shader );
			_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );

			scene->setCameraPosToShader( _shader );

			scene->setDirectLightPropToShader( _shader );
			scene->setPointLightsPropToShader( _shader );
			scene->setFlashLightsPropToShader( _shader );
		}

		_arrayBuffer.drawArrays( GL_TRIANGLES, 0 );

		glDisable( GL_CULL_FACE );
	}
	void Cube::updateVetices()
	{
		PosNormalVertex vertices[] = {
			//back plane
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f),  Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f),  Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3(0.0f, 0.0f, 0.0f), Vec3( 0.0f, 0.0f, -1.0f ) },
			
			//front plane
			{ Vec3( 0.0f, 0.0f,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _cubeSize, 0.0f,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( 0.0f, 0.0f,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },

			//left plane
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f,  _cubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },

			//right plane
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, _cubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			
			//bottom plane
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f,  _cubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f,  _cubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, _cubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },

			//top plane
			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) }
		};

		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices, sizeof(PosNormalVertex), sizeof(vertices)/sizeof(PosNormalVertex) );

	}
	void Cube::setCubeSize( float size )
	{
		if ( size > 0.0f && abs(_cubeSize - size) > FLT_EPSILON  )
		{
			_cubeSize = size;
			_verticesDirty = true;
		}
	}
}
