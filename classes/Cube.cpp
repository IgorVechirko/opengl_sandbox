#include "Cube.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Scene.h"
#include "WorkingScope.h"
#include "Camera.h"
#include "GLContext.h"

#include "ResourcesManager.h"

#include "PointLightSource.h"
#include "DirectLightSource.h"
#include "Flashlight.h"

namespace GLSandbox
{

	Cube::Cube()
		: _texture( nullptr )
		, _shader( nullptr )
		, _vbo( 0 )
		, _vao( 0 )
		, _ebo( 0 )
	{
	}
	Cube::~Cube()
	{
	}


	bool Cube::initWithFilePath( const std::string& filePath )
	{	
		Node::init();
	
		auto texture = createRefWithInitializer<Texture2D>(&Texture2D::initWithFilePath, filePath );

		if ( texture )
		{
			setTexture( texture );
			return true;
		}
		else
			return false;
	}
	void Cube::setShaderProgram( ShaderProgram* program )
	{
		if ( program )
		{
			if ( _shader )
				_shader->release();

			_shader = program;
			_shader->retain();
		}
	}
	void Cube::setTexture( Texture2D* texture )
	{
		if ( texture )
		{
			if ( _texture )
				_texture->release();

			_texture = texture;
			_texture->retain();

			Size textSize( _texture->getWidth(), _texture->getHeight() );


			_vertices = {	0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
							 textSize.x, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
							 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
							 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
							0.0f,  textSize.x, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
							0.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,

							0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f,
							 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,  0.0f,  0.0f,  1.0f,
							 textSize.x,  textSize.x,  textSize.x,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
							 textSize.x,  textSize.x,  textSize.x,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f,
							0.0f,  textSize.x,  textSize.x,  0.0f, 1.0f,  0.0f,  0.0f,  1.0f,
							0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f,

							0.0f,  textSize.x,  textSize.x,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
							0.0f,  textSize.x, 0.0f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
							0.0f, 0.0f, 0.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
							0.0f, 0.0f, 0.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
							0.0f, 0.0f,  textSize.x,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
							0.0f,  textSize.x,  textSize.x,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

							 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f,
							 textSize.x,  textSize.x, 0.0f,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f,
							 textSize.x, 0.0f, 0.0f,  0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
							 textSize.x, 0.0f, 0.0f,  0.0f, 1.0f,  1.0f,  0.0f,  0.0f,
							 textSize.x, 0.0f,  textSize.x,  0.0f, 0.0f,  1.0f,  0.0f,  0.0f,
							 textSize.x,  textSize.x,  textSize.x,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f,

							0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
							 textSize.x, 0.0f, 0.0f,  1.0f, 1.0f,  0.0f, -1.0f,  0.0f,
							 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
							 textSize.x, 0.0f,  textSize.x,  1.0f, 0.0f,  0.0f, -1.0f,  0.0f,
							0.0f, 0.0f,  textSize.x,  0.0f, 0.0f,  0.0f, -1.0f,  0.0f,
							0.0f, 0.0f, 0.0f,  0.0f, 1.0f,  0.0f, -1.0f,  0.0f,

							0.0f,  textSize.x, 0.0f,  0.0f, 1.0f,  0.0f, 1.0f,  0.0f,
							 textSize.x,  textSize.x, 0.0f,  1.0f, 1.0f,  0.0f, 1.0f,  0.0f,
							 textSize.x,  textSize.x,  textSize.x, 1.0f, 0.0f,  0.0f, 1.0f,  0.0f,
							 textSize.x,  textSize.x,  textSize.x, 1.0f, 0.0f,  0.0f, 1.0f,  0.0f,
							0.0f,  textSize.x,  textSize.x,  0.0f, 0.0f, 0.0f, 1.0f,  0.0f,
							0.0f,  textSize.x, 0.0f,  0.0f, 1.0f,  0.0f, 1.0f,  0.0f };

			_indices = { 0, 1, 2,
						 1, 2, 3 };

			setShaderProgram( createRefWithInitializer<ShaderProgram>(&ShaderProgram::initWithSrc, getResMng()->getResStr("CUBE_VERTEX"), getResMng()->getResStr("CUBE_FRAGMENT") ) );

			glGenVertexArrays(1, &_vao);
			glGenBuffers(1, &_vbo);
			glGenBuffers(1, &_ebo);

			glBindVertexArray( _vao );

			const GLfloat* vertices = &_vertices[0];
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*_vertices.size(), vertices, GL_STATIC_DRAW );

			const GLuint* indices = &_indices[0];
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*_indices.size(), indices, GL_STATIC_DRAW );

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)0);
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(3*sizeof(GLfloat)));
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*8, (GLvoid*)(5*sizeof(GLfloat)));
			glEnableVertexAttribArray(2);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}
	void Cube::draw( GLRender* render, const Mat4& transform )
	{
		if ( _texture )
			glBindTexture(GL_TEXTURE_2D, _texture->getTextureID() );

		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		glBindVertexArray(_vao);

		if( _shader )
		{
			_shader->useProgram();

			GLuint transModelLoc = glGetUniformLocation( _shader->getProgramID(), "model" );
			GLuint transViewLoc = glGetUniformLocation ( _shader->getProgramID(), "view" );
			GLuint transProjLoc = glGetUniformLocation( _shader->getProgramID(), "projection" );
			GLuint cameraPosLoc = glGetUniformLocation( _shader->getProgramID(), "cameraPos" );

			auto& cameraPos = getGLContext()->getScene()->getCamera()->getPosition();

			glProgramUniformMatrix4fv( _shader->getProgramID(), transModelLoc, 1, GL_FALSE, glm::value_ptr( transform ) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), transViewLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			glProgramUniformMatrix4fv( _shader->getProgramID(), transProjLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );
			glProgramUniform3f( _shader->getProgramID(), cameraPosLoc, cameraPos.x, cameraPos.y, cameraPos.z );


			GLuint materialAmbientLoc = glGetUniformLocation( _shader->getProgramID(), "material.ambient" );
			GLuint materialDiffuseLoc = glGetUniformLocation( _shader->getProgramID(), "material.diffuse" );
			GLuint materialSpecularLoc = glGetUniformLocation( _shader->getProgramID(), "material.specular" );
			GLuint materialShininessLoc = glGetUniformLocation( _shader->getProgramID(), "material.shininess" );

			const auto& material = getMaterial();

			glProgramUniform3f( _shader->getProgramID(), materialAmbientLoc, material.ambient.r, material.ambient.g, material.ambient.b );
			glProgramUniform3f( _shader->getProgramID(), materialDiffuseLoc, material.diffuse.r, material.diffuse.g, material.diffuse.b );
			glProgramUniform3f( _shader->getProgramID(), materialSpecularLoc, material.specular.r, material.specular.g, material.specular.b );
			glProgramUniform1f( _shader->getProgramID(), materialShininessLoc, material.shininess );

		
			if ( getGLContext()->getScene()->getDirectionLight() )
			{
				auto lightSource = getGLContext()->getScene()->getDirectionLight();
				LightProperties lightProperties = lightSource->getLightProperties();
				glm::vec3 lightDirection = lightSource->getDirection();

				GLuint lightPropAmbientLoc = glGetUniformLocation( _shader->getProgramID(), "directLight.ambient" );
				GLuint lightPropDiffuseLoc = glGetUniformLocation( _shader->getProgramID(), "directLight.diffuse" );
				GLuint lightPropSpecularLoc = glGetUniformLocation( _shader->getProgramID(), "directLight.specular" );
				GLuint lightPropDirectLoc = glGetUniformLocation( _shader->getProgramID(), "directLight.direction" );

				glProgramUniform3f( _shader->getProgramID(), lightPropAmbientLoc, lightProperties.ambient.r, lightProperties.ambient.g, lightProperties.ambient.b );
				glProgramUniform3f( _shader->getProgramID(), lightPropDiffuseLoc, lightProperties.diffuse.r, lightProperties.diffuse.g, lightProperties.diffuse.b );
				glProgramUniform3f( _shader->getProgramID(), lightPropSpecularLoc, lightProperties.specular.r, lightProperties.specular.g, lightProperties.specular.b );
				glProgramUniform3f( _shader->getProgramID(), lightPropDirectLoc, lightDirection.x, lightDirection.y, lightDirection.z );
			}
		

			if ( getGLContext()->getScene() )
			{
				const auto& pointLights = getGLContext()->getScene()->getPointLights();

				GLuint ponitLighstCount = glGetUniformLocation( _shader->getProgramID(), "pointLightsCount" );
				glProgramUniform1i( _shader->getProgramID(), ponitLighstCount, pointLights.size() );

				for( int lightIndx = 0; lightIndx < pointLights.size(); lightIndx++ )
				{
					auto light = pointLights[ lightIndx ];

					GLuint posLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].pos" ).c_str() );
					GLuint constantLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].constant" ).c_str() );
					GLuint linearLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].linear" ).c_str() );
					GLuint quadraticLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].quadratic" ).c_str() );
					GLuint ambientLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].ambient" ).c_str() );
					GLuint diffuseLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].diffuse" ).c_str() );
					GLuint specularLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "pointLights[" + std::to_string(lightIndx) + "].specular" ).c_str() );

					glProgramUniform3f( _shader->getProgramID(), posLoc, light->getPosition().x, light->getPosition().y, light->getPosition().z );

					glProgramUniform1f( _shader->getProgramID(), constantLoc, light->getAttenuation().constant );
					glProgramUniform1f( _shader->getProgramID(), linearLoc, light->getAttenuation().linear );
					glProgramUniform1f( _shader->getProgramID(), quadraticLoc, light->getAttenuation().quadratic );

					glProgramUniform3f( _shader->getProgramID(), ambientLoc, light->getLightProperties().ambient.r, light->getLightProperties().ambient.g, light->getLightProperties().ambient.b );
					glProgramUniform3f( _shader->getProgramID(), diffuseLoc, light->getLightProperties().diffuse.r, light->getLightProperties().diffuse.g, light->getLightProperties().diffuse.b );
					glProgramUniform3f( _shader->getProgramID(), specularLoc, light->getLightProperties().specular.r, light->getLightProperties().specular.g, light->getLightProperties().specular.b );
				}

				const auto& flashlights = getGLContext()->getScene()->getFlashLights();

				GLuint flashlightsCount = glGetUniformLocation( _shader->getProgramID(), "flashlightsCount" );
				glProgramUniform1i( _shader->getProgramID(), flashlightsCount, flashlights.size() );

				for( int lightIndx = 0; lightIndx < flashlights.size(); lightIndx++ )
				{
					auto light = flashlights[ lightIndx ];

					GLuint posLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].pos" ).c_str() );
					GLuint directLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].direction" ).c_str() );
					GLuint cutOffAngleCosLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].cutOffAngleCos" ).c_str() );
					GLuint outerCutOffAngleCosLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].outerCutOffAngleCos" ).c_str() );
					GLuint constantLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].constant" ).c_str() );
					GLuint linearLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].linear" ).c_str() );
					GLuint quadraticLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].quadratic" ).c_str() );
					GLuint ambientLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].ambient" ).c_str() );
					GLuint diffuseLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].diffuse" ).c_str() );
					GLuint specularLoc = glGetUniformLocation( _shader->getProgramID(), std::string( "flashlights[" + std::to_string(lightIndx) + "].specular" ).c_str() );

					glProgramUniform3f( _shader->getProgramID(), posLoc, light->getPosition().x, light->getPosition().y, light->getPosition().z );
					glProgramUniform3f( _shader->getProgramID(), directLoc, light->getDirection().x, light->getDirection().y, light->getDirection().z );
					glProgramUniform1f( _shader->getProgramID(), cutOffAngleCosLoc, glm::cos(glm::radians(light->getCutOffAngle())) );
					glProgramUniform1f( _shader->getProgramID(), outerCutOffAngleCosLoc, glm::cos(glm::radians(light->getOuterCutOffAngle())) );

					glProgramUniform1f( _shader->getProgramID(), constantLoc, light->getAttenuation().constant );
					glProgramUniform1f( _shader->getProgramID(), linearLoc, light->getAttenuation().linear );
					glProgramUniform1f( _shader->getProgramID(), quadraticLoc, light->getAttenuation().quadratic );

					glProgramUniform3f( _shader->getProgramID(), ambientLoc, light->getLightProperties().ambient.r, light->getLightProperties().ambient.g, light->getLightProperties().ambient.b );
					glProgramUniform3f( _shader->getProgramID(), diffuseLoc, light->getLightProperties().diffuse.r, light->getLightProperties().diffuse.g, light->getLightProperties().diffuse.b );
					glProgramUniform3f( _shader->getProgramID(), specularLoc, light->getLightProperties().specular.r, light->getLightProperties().specular.g, light->getLightProperties().specular.b );
				}

			}

			glDrawArrays(GL_TRIANGLES, 0, _vertices.size() );
		}

		//TODO is necessary unbind texture ?
		//if ( _texture )
			//glBindTexture(GL_TEXTURE_2D, NULL );
	
		glBindVertexArray(0);
	}

}