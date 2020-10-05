#include "Skybox.h"

#include "CubeMap.h"
#include "ShaderProgram.h"
#include "ShadersCache.h"
#include "DrawTypes.h"
#include "GLContext.h"
#include "Scene.h"
#include "Texture2D.h"
#include "Camera.h"

namespace GLSandbox
{

	Skybox::Skybox()
	{
	}
	Skybox::~Skybox()
	{
	}
	bool Skybox::initWithPlanesPaths( const std::array<std::string,6>& planesPaths )
	{
		auto cubeMap = createRefWithInitializer<CubeMap>( &CubeMap::initWithPlanesPaths, planesPaths );
		if ( !cubeMap )
		{
			return false;
		}

		setCubeMap( cubeMap );

		setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::NO_MODEL_CUBE_SAMPLER ) );

		_arrayBuffer.genBuffer( VertexArrayObject::BufferType::VERTEX );

		std::vector<PosVertex> vertices = {
			{Vec3( -1.0f,  1.0f, -1.0f )},
			{Vec3( -1.0f, -1.0f, -1.0f )},
			{Vec3( 1.0f, -1.0f, -1.0f )},
			{Vec3( 1.0f, -1.0f, -1.0f )},
			{Vec3( 1.0f,  1.0f, -1.0f )},
			{Vec3( -1.0f,  1.0f, -1.0f )},

			{Vec3( -1.0f, -1.0f,  1.0f )},
			{Vec3( -1.0f, -1.0f, -1.0f )},
			{Vec3( -1.0f,  1.0f, -1.0f )},
			{Vec3( -1.0f,  1.0f, -1.0f )},
			{Vec3( -1.0f,  1.0f,  1.0f )},
			{Vec3( -1.0f, -1.0f,  1.0f )},

			{Vec3( 1.0f, -1.0f, -1.0f )},
			{Vec3( 1.0f, -1.0f,  1.0f )},
			{Vec3( 1.0f,  1.0f,  1.0f )},
			{Vec3( 1.0f,  1.0f,  1.0f )},
			{Vec3( 1.0f,  1.0f, -1.0f )},
			{Vec3( 1.0f, -1.0f, -1.0f )},

			{Vec3( -1.0f, -1.0f,  1.0f )},
			{Vec3( -1.0f,  1.0f,  1.0f )},
			{Vec3( 1.0f,  1.0f,  1.0f )},
			{Vec3( 1.0f,  1.0f,  1.0f )},
			{Vec3( 1.0f, -1.0f,  1.0f )},
			{Vec3( -1.0f, -1.0f,  1.0f )},

			{Vec3( -1.0f,  1.0f, -1.0f )},
			{Vec3( 1.0f,  1.0f, -1.0f )},
			{Vec3( 1.0f,  1.0f,  1.0f )},
			{Vec3( 1.0f,  1.0f,  1.0f )},
			{Vec3( -1.0f,  1.0f,  1.0f )},
			{Vec3( -1.0f,  1.0f, -1.0f )},

			{Vec3( -1.0f, -1.0f, -1.0f )},
			{Vec3( -1.0f, -1.0f,  1.0f )},
			{Vec3( 1.0f, -1.0f, -1.0f )},
			{Vec3( 1.0f, -1.0f, -1.0f )},
			{Vec3( -1.0f, -1.0f,  1.0f )},
			{Vec3( 1.0f, -1.0f,  1.0f )}
		};

		_arrayBuffer.setupBufferData( VertexArrayObject::BufferType::VERTEX, vertices.data(), sizeof(PosVertex), vertices.size() );

		_arrayBuffer.setupAttribPointer( 0, 3, GL_FLOAT, false, sizeof(GLfloat)*3, (GLvoid*)0 );


		return true;
	}
	void Skybox::draw()
	{
		glDepthFunc( GL_LEQUAL );

		if ( getCubeMap() )
			getCubeMap()->useCubeMap(0);

		auto shader = getShaderProgram();
		if ( shader )
		{
			auto scene = getGLContext()->getScene();

			auto view = scene->getCamera()->getView();
			view = Mat4( glm::mat3x3(view) );

			shader->setUniformMatrix4fv( "u_view", 1, false, glm::value_ptr( view ) );
			scene->setProjectionToShader( shader );

			shader->setUniform1i( "skybox", 0 );

			shader->useProgram();
		}
		
		_arrayBuffer.drawArrays( GL_TRIANGLES, 0 );

		glDepthFunc( GL_LESS );
	}
}