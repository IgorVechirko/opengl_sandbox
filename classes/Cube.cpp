#include "Cube.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Scene.h"
#include "WorkingScope.h"
#include "Camera.h"
#include "GLContext.h"
#include "DrawTypes.h"

#include "ResourcesManager.h"

#include "PointLightSource.h"
#include "DirectLightSource.h"
#include "Flashlight.h"

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

		setShaderProgram( createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, positionNormalLightProp_vert, positionNormalLightProp_frag) );

		return true;
	}
	void Cube::draw( GLRender* render, const Mat4& transform )
	{
		if ( _verticesDirty )
		{
			updateVetices();
			_verticesDirty = false;
		}

		if( _shader )
		{
			_shader->useProgram();

			_shader->setUniformMatrix4fv( "u_model", 1, false, glm::value_ptr( transform ) );
			_shader->setUniformMatrix4fv( "u_view", 1, false, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			_shader->setUniformMatrix4fv( "u_projection", 1, false, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );

			auto& cameraPos = getGLContext()->getScene()->getCamera()->getPosition();
			_shader->setUniform3f( "u_cameraPos", cameraPos.x, cameraPos.y, cameraPos.z );

			const auto& material = getMaterial();
			_shader->setMaterialUniforms( material, "u_material", "ambient", "diffuse", "specular", "shininess" );


			if ( getGLContext()->getScene()->getDirectionLight() )
			{
				auto lightSource = getGLContext()->getScene()->getDirectionLight();
				LightProperties lightProperties = lightSource->getLightProperties();
				glm::vec3 lightDirection = lightSource->getDirection();

				_shader->setLightPropUniforms( lightProperties, "u_directLight", "ambient", "diffuse", "specular" );
				_shader->setUniform3f( "u_directLight.direction", lightDirection.x, lightDirection.y, lightDirection.z );
			}
		
			const auto& pointLights = getGLContext()->getScene()->getPointLights();
			_shader->setUniform1i( "u_pointLightsCount", pointLights.size() );

			for( int lightIndx = 0; lightIndx < pointLights.size(); lightIndx++ )
			{
				const auto& light = pointLights[lightIndx];
				const auto& lightPos = light->getPosition();

				_shader->setLightPropUniforms( light->getLightProperties(), "u_pointLights[" + std::to_string(lightIndx) + "]", "ambient", "diffuse", "specular" );
				_shader->setAttenuationCoefsUniforms( light->getAttenuation(), "u_pointLights[" + std::to_string(lightIndx) + "]", "constant", "linear", "quadratic" );
				_shader->setUniform3f( "u_pointLights[" + std::to_string(lightIndx) + "].pos", lightPos.x, lightPos.y, lightPos.z );
			}

			const auto& flashlights = getGLContext()->getScene()->getFlashLights();
			_shader->setUniform1i( "u_flashlightsCount", flashlights.size() );

			for( int lightIndx = 0; lightIndx < flashlights.size(); lightIndx++ )
			{
				const auto& light = flashlights[lightIndx];
				const auto& lightPos = light->getPosition();
				const auto& lightDirection = light->getDirection();

				_shader->setLightPropUniforms( light->getLightProperties(), "u_flashlights[" + std::to_string(lightIndx) + "]", "ambient", "diffuse", "specular" );
				_shader->setAttenuationCoefsUniforms( light->getAttenuation(), "u_flashlights[" + std::to_string(lightIndx) + "]", "constant", "linear", "quadratic" );
				_shader->setUniform3f( "u_flashlights[" + std::to_string(lightIndx) + "].pos", lightPos.x, lightPos.y, lightPos.z );

				_shader->setUniform3f( "u_flashlights[" + std::to_string(lightIndx) + "].direction", lightDirection.x, lightDirection.y, lightDirection.z );
				_shader->setUniform1f( "u_flashlights[" + std::to_string(lightIndx) + "].cutOffAngleCos", glm::cos(glm::radians(light->getCutOffAngle())) );
				_shader->setUniform1f( "u_flashlights[" + std::to_string(lightIndx) + "].outerCutOffAngleCos", glm::cos(glm::radians(light->getOuterCutOffAngle())) );
			}
		}

		_arrayBuffer.drawArrays( GL_TRIANGLES, 0 );
	}
	void Cube::updateVetices()
	{
		PosNormalVertex vertices[] = {
			{ Vec3(0.0f, 0.0f, 0.0f), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f),  Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f),  Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, 0.0f, -1.0f ) },

			{ Vec3( 0.0f, 0.0f,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _cubeSize, 0.0f,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },
			{ Vec3( 0.0f, 0.0f,  _cubeSize ), Vec3( 0.0f,  0.0f,  1.0f ) },

			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f,  _cubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( -1.0f,  0.0f,  0.0f ) },

			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, _cubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 1.0f,  0.0f,  0.0f ) },

			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f,  _cubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( _cubeSize, 0.0f,  _cubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, _cubeSize ), Vec3( 0.0f, -1.0f,  0.0f ) },
			{ Vec3( 0.0f, 0.0f, 0.0f ), Vec3( 0.0f, -1.0f,  0.0f ) },

			{ Vec3( 0.0f,  _cubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize, 0.0f ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( _cubeSize,  _cubeSize,  _cubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
			{ Vec3( 0.0f,  _cubeSize,  _cubeSize ), Vec3( 0.0f, 1.0f,  0.0f ) },
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
