#ifndef ShaderProgram_H
#define ShaderProgram_H

#include "Common.h"

#include "Ref.h"

namespace GLSandbox
{
	struct Material;
	struct LightProperties;
	struct LightAttenuationCoefs;
	class ShaderProgram : public Ref
	{

		GLuint _programID;
	

		public:

			ShaderProgram();
			virtual ~ShaderProgram();
			MAKE_UNCOPYABLE(ShaderProgram);

			bool initWithSrc( const std::string& verSrc, const std::string& fragSrc );

			[[deprecated]] 
			GLuint getProgramID() const;

			void useProgram();

			GLint getUniformLocation( const std::string& uniformName );

			void setUniform1d( const std::string& uniformName, GLdouble x );
			void setUniform1dv( const std::string& uniformName, GLsizei size, const GLdouble* val );
			void setUniform1f( const std::string& uniformName, GLfloat x );
			void setUniform1fv( const std::string& uniformName, GLsizei size, const GLfloat* val );
			void setUniform1i( const std::string& uniformName, GLint x );
			void setUniform1iv( const std::string& uniformName, GLsizei size, const GLint* val );
			void setUniform1ui( const std::string& uniformName, GLuint x );
			void setUniform1uiv( const std::string& uniformName, GLsizei size, const GLuint* val );

			void setUniform2d( const std::string& uniformName, GLdouble x, GLdouble y );
			void setUniform2dv( const std::string& uniformName, GLsizei size, const GLdouble* val );
			void setUniform2f( const std::string& uniformName, GLfloat x, GLfloat y );
			void setUniform2fv( const std::string& uniformName, GLsizei size, const GLfloat* val );
			void setUniform2i( const std::string& uniformName, GLint x, GLint y );
			void setUniform2iv( const std::string& uniformName, GLsizei size, const GLint* val );
			void setUniform2ui( const std::string& uniformName, GLuint x, GLuint y );
			void setUniform2uiv( const std::string& uniformName, GLsizei size, const GLuint* val );

			void setUniform3d( const std::string& uniformName, GLdouble x, GLdouble y, GLdouble z );
			void setUniform3dv( const std::string& uniformName, GLsizei size, const GLdouble* val );
			void setUniform3f( const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z );
			void setUniform3fv( const std::string& uniformName, GLsizei size, const GLfloat* val );
			void setUniform3i( const std::string& uniformName, GLint x, GLint y, GLint z );
			void setUniform3iv( const std::string& uniformName, GLsizei size, const GLint* val );
			void setUniform3ui( const std::string& uniformName, GLuint x, GLuint y, GLuint z );
			void setUniform3uiv( const std::string& uniformName, GLsizei size, const GLuint* val );

			void setUniform4d( const std::string& uniformName, GLdouble x, GLdouble y, GLdouble z, GLdouble w );
			void setUniform4dv( const std::string& uniformName, GLsizei size, const GLdouble* val );
			void setUniform4f( const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w );
			void setUniform4fv( const std::string& uniformName, GLsizei size, const GLfloat* val );
			void setUniform4i( const std::string& uniformName, GLint x, GLint y, GLint z, GLint w );
			void setUniform4iv( const std::string& uniformName, GLsizei size, const GLint* val );
			void setUniform4ui( const std::string& uniformName, GLuint x, GLuint y, GLuint z, GLuint w );
			void setUniform4uiv( const std::string& uniformName, GLsizei size, const GLuint* val );

			void setUniformMatrix2dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix2fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix2x3dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix2x3fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix2x4dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix2x4fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix3dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix3fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix3x2dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix3x2fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix3x4dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix3x4fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix4dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix4fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix4x2dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix4x2fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );
			void setUniformMatrix4x3dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val );
			void setUniformMatrix4x3fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val );

			void setMaterialUniforms( const Material& material, const std::string& strName, const std::string& ambMemName, const std::string& diffMemName, const std::string& specMemName, const std::string& shineMemeName );
			void setLightPropUniforms( const LightProperties& prop, const std::string& strName, const std::string& ambMemName, const std::string& diffMemName, const std::string& specMemName );
			void setAttenuationCoefsUniforms( const LightAttenuationCoefs& coefs, const std::string& strName, const std::string& constMemName, const std::string& linearMemName, const std::string& quadraticMemName );

	};

}


#endif