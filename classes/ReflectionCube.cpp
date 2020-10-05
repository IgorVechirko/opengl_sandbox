#include "ReflectionCube.h"

#include "ShaderProgram.h"
#include "Scene.h"
#include "GLContext.h"
#include "ShadersCache.h"
#include "Skybox.h"
#include "CubeMap.h"


namespace GLSandbox
{

	ReflectionCube::ReflectionCube()
		: _reflectionCubeSize( 1.0f )
		, _verticesDirty( true )
	{
	}
	ReflectionCube::~ReflectionCube()
	{
	}


	bool ReflectionCube::onInit()
	{	
		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );

		_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*6, (GLvoid*)0 );
		_arrayBuffer.setupAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*6, (GLvoid*)(3*sizeof(GLfloat)) );

		setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::POS_NORMAL_SKYBOX_REFLECTION ) );

		return true;
	}
	void ReflectionCube::draw( const Mat4& transform )
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

			scene->setProjectionToShader( _shader );
			scene->setViewToShader( _shader );
			_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );

			scene->setCameraPosToShader( _shader );

			if( scene->getSkybox() )
			{
				_shader->setUniform1i( "u_skybox", 0 );
				scene->getSkybox()->getCubeMap()->useCubeMap();
			}
		}

		_arrayBuffer.drawArrays( GL_TRIANGLES, 0 );

		glDisable( GL_CULL_FACE );
	}
	void ReflectionCube::updateVetices()
	{
		PosNormalVertex vertices[] = {
			//back plane
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( 0.0f,  _reflectionCubeSize, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize, 0.0f),  Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize, 0.0f),  Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3(0.0f, 0.0f, 0.0f), Vec3( 0.0f, 0.0f, -1.0f ) },
			
			//front plane
			{ Vec3( 0.0f, 0.0f,  _reflectionCubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f,  _reflectionCubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( 0.0f,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( 0.0f, 0.0f,  _reflectionCubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },

			//left plane
			{ Vec3( 0.0f,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f,  _reflectionCubeSize, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f,  _reflectionCubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },

			//right plane
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f, _reflectionCubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			
			//bottom plane
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f,  _reflectionCubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize, 0.0f,  _reflectionCubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, _reflectionCubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },

			//top plane
			{ Vec3( 0.0f,  _reflectionCubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( 0.0f,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize,  _reflectionCubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _reflectionCubeSize,  _reflectionCubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( 0.0f,  _reflectionCubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) }
		};

		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices, sizeof(PosNormalVertex), sizeof(vertices)/sizeof(PosNormalVertex) );

	}
	void ReflectionCube::setReflectionCubeSize( float size )
	{
		if ( size > 0.0f && abs(_reflectionCubeSize - size) > FLT_EPSILON  )
		{
			_reflectionCubeSize = size;
			_verticesDirty = true;
		}
	}
}
