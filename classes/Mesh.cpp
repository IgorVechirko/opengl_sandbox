#include "Mesh.h"
#include "ShaderProgram.h"

#include "Camera.h"
#include "DirectLightSource.h"
#include "WorkingScope.h"
#include "Scene.h"
#include "GLContext.h"


_USEVE

Mesh::Mesh()
	: _vao( 0 )
	, _vbo( 0 )
	, _ebo( 0 )
{
}
Mesh::Mesh( WorkingScope* scope, const std::vector<PosNormaTextCordVertex>& vetrices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures )
	: _vao( 0 )
	, _vbo( 0 )
	, _ebo( 0 )
	, WorkingScopeProvider( scope )
{
	_vertices = vetrices;
	_indices = indices;
	_textures = textures;

	setupMesh();
}
Mesh::~Mesh()
{
}
void Mesh::setupMesh()
{
	glGenVertexArrays( 1, &_vao );
	glGenBuffers( 1, &_vbo );
	glGenBuffers( 1, &_ebo );

	glBindVertexArray( _vao );

	glBindBuffer( GL_ARRAY_BUFFER, _vbo );	
	glBufferData( GL_ARRAY_BUFFER, _vertices.size() * sizeof(PosNormaTextCordVertex), &_vertices[0], GL_STATIC_DRAW );
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, _ebo );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW );
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer( 0, 3, GL_FLOAT, false, sizeof(PosNormaTextCordVertex), (void*)0 );

	glEnableVertexAttribArray(1);
	glVertexAttribPointer( 1, 3, GL_FLOAT, false, sizeof(PosNormaTextCordVertex), (void*)offsetof(PosNormaTextCordVertex, normal) );

	glEnableVertexAttribArray(2);
	glVertexAttribPointer( 2, 2, GL_FLOAT, false, sizeof(PosNormaTextCordVertex), (void*)offsetof(PosNormaTextCordVertex, textCord) );

	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}
void Mesh::draw( ShaderProgram* shader, const Mat4& transform )
{
	if ( shader )
	{
		shader->useProgram();

		if ( getGLContext()->getScene()->getCamera() )
		{
			GLuint transModelLoc = glGetUniformLocation( shader->getProgramID(), "model" );
			GLuint transViewLoc = glGetUniformLocation ( shader->getProgramID(), "view" );
			GLuint transProjLoc = glGetUniformLocation( shader->getProgramID(), "projection" );

			auto& cameraPos = getGLContext()->getScene()->getCamera()->getPosition();

			glProgramUniformMatrix4fv( shader->getProgramID(), transModelLoc, 1, GL_FALSE, glm::value_ptr( transform ) );
			glProgramUniformMatrix4fv( shader->getProgramID(), transViewLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getView() ) );
			glProgramUniformMatrix4fv( shader->getProgramID(), transProjLoc, 1, GL_FALSE, glm::value_ptr( getGLContext()->getScene()->getCamera()->getProjection() ) );
		}

		if ( getGLContext()->getScene()->getDirectionLight() )
		{
			auto lightSource = getGLContext()->getScene()->getDirectionLight();
			LightProperties lightProperties = lightSource->getLightProperties();
			glm::vec3 lightDirection = lightSource->getDirection();

			GLuint lightPropAmbientLoc = glGetUniformLocation( shader->getProgramID(), "directLight.ambient" );
			GLuint lightPropDiffuseLoc = glGetUniformLocation( shader->getProgramID(), "directLight.diffuse" );
			GLuint lightPropSpecularLoc = glGetUniformLocation( shader->getProgramID(), "directLight.specular" );
			GLuint lightPropDirectLoc = glGetUniformLocation( shader->getProgramID(), "directLight.direction" );

			glProgramUniform3f( shader->getProgramID(), lightPropAmbientLoc, lightProperties.ambient.r, lightProperties.ambient.g, lightProperties.ambient.b );
			glProgramUniform3f( shader->getProgramID(), lightPropDiffuseLoc, lightProperties.diffuse.r, lightProperties.diffuse.g, lightProperties.diffuse.b );
			glProgramUniform3f( shader->getProgramID(), lightPropSpecularLoc, lightProperties.specular.r, lightProperties.specular.g, lightProperties.specular.b );
			glProgramUniform3f( shader->getProgramID(), lightPropDirectLoc, lightDirection.x, lightDirection.y, lightDirection.z );
		}

		unsigned int diffuseNr = 1;
		unsigned int specularNr = 1;
		for( unsigned int i = 0; i < _textures.size(); i ++)
		{
			glActiveTexture( GL_TEXTURE0 + i);

			std::string samplerName;
			auto type = _textures[ i ].type;

			if ( type == eTextureType::SPECULAR_LIHGT_MAP )
			{
				samplerName = "texture_specular" + std::to_string(specularNr++);
			}
			else if ( type == eTextureType::DIFFUSE_LIHGT_MAP )
			{
				samplerName = "texture_diffuse" + std::to_string(specularNr++);
			}

			auto uniformLoc = glGetUniformLocation( shader->getProgramID(), samplerName.c_str() );
			glProgramUniform1i( shader->getProgramID(), uniformLoc, i );
			glBindTexture(GL_TEXTURE_2D, _textures[i].id ); 
		}

		glActiveTexture( GL_TEXTURE0 );


		glBindVertexArray( _vao );
		glDrawElements( GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0 );
	}
}