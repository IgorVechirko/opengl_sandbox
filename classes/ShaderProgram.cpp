#include "ShaderProgram.h"

#include "MaterialsAndLightsTypes.h"



namespace GLSandbox
{

	ShaderProgram::ShaderProgram()
		: _programID(NULL)
	{
	}
	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(_programID);
	}
	bool ShaderProgram::initWithSrc( const std::string& verSrc, const std::string& fragSrc )
	{
		if ( verSrc.empty() || fragSrc.empty() )
			return false;

		const char* vertexChar = verSrc.c_str();
		const char* fragmentChar = fragSrc.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexChar, NULL);
		glCompileShader(vertexShader);

		GLint logSize = 0;
		glGetShaderiv( vertexShader, GL_INFO_LOG_LENGTH, &logSize);
		if (logSize)
		{
			std::shared_ptr<GLchar> infoLog = std::shared_ptr<GLchar>(new GLchar[logSize]);
			glGetShaderInfoLog(vertexShader, logSize, NULL, infoLog.get());
			Console::log( "vertex shader compile error:\n", verSrc, "\n", infoLog );
			logSize = 0;

			return false;
		}


		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentChar, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv( fragmentShader, GL_INFO_LOG_LENGTH, &logSize);
		if (logSize)
		{
			std::shared_ptr<GLchar> infoLog = std::shared_ptr<GLchar>(new GLchar[logSize]);
			glGetShaderInfoLog(fragmentShader, logSize, NULL, infoLog.get());
			Console::log( "fragment shader compile error:\n", fragSrc, "\n", infoLog );
			logSize = 0;

			return false;
		}


		_programID = glCreateProgram();
		glAttachShader(_programID, vertexShader);
		glAttachShader(_programID, fragmentShader);
		glLinkProgram(_programID);

		glGetProgramiv( _programID, GL_INFO_LOG_LENGTH, &logSize );
		if ( logSize )
		{
			std::shared_ptr<GLchar> infoLog = std::shared_ptr<GLchar>(new GLchar[logSize]);
			glGetProgramInfoLog( _programID, logSize, NULL, infoLog.get() );
			Console::log( "program compile error: ", infoLog );

			return false;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return true;
	}
	GLuint ShaderProgram::getProgramID() const
	{
		return _programID;
	}
	void ShaderProgram::useProgram()
	{
		glUseProgram(_programID);
	}
	void ShaderProgram::setUniform1d( const std::string& uniformName, GLdouble x )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1d( _programID, location, x );
	}
	void ShaderProgram::setUniform1dv( const std::string& uniformName, GLsizei size, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1dv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform1f( const std::string& uniformName, GLfloat x )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1f( _programID, location, x );
	}
	void ShaderProgram::setUniform1fv( const std::string& uniformName, GLsizei size, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1fv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform1i( const std::string& uniformName, GLint x )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1i( _programID, location, x );
	}
	void ShaderProgram::setUniform1iv( const std::string& uniformName, GLsizei size, const GLint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1iv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform1ui( const std::string& uniformName, GLuint x )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1ui( _programID, location, x );
	}
	void ShaderProgram::setUniform1uiv( const std::string& uniformName, GLsizei size, const GLuint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform1uiv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform2d( const std::string& uniformName, GLdouble x, GLdouble y )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2d( _programID, location, x, y );
	}
	void ShaderProgram::setUniform2dv( const std::string& uniformName, GLsizei size, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2dv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform2f( const std::string& uniformName, GLfloat x, GLfloat y )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2f( _programID, location, x, y );
	}
	void ShaderProgram::setUniform2fv( const std::string& uniformName, GLsizei size, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2fv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform2i( const std::string& uniformName, GLint x, GLint y )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2i( _programID, location, x, y );
	}
	void ShaderProgram::setUniform2iv( const std::string& uniformName, GLsizei size, const GLint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2iv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform2ui( const std::string& uniformName, GLuint x, GLuint y )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2ui( _programID, location, x, y );
	}
	void ShaderProgram::setUniform2uiv( const std::string& uniformName, GLsizei size, const GLuint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform2uiv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform3d( const std::string& uniformName, GLdouble x, GLdouble y, GLdouble z )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3d( _programID, location, x, y, z );
	}
	void ShaderProgram::setUniform3dv( const std::string& uniformName, GLsizei size, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3dv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform3f( const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3f( _programID, location, x, y, z );
	}
	void ShaderProgram::setUniform3fv( const std::string& uniformName, GLsizei size, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3fv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform3i( const std::string& uniformName, GLint x, GLint y, GLint z )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3i( _programID, location, x, y, z );
	}
	void ShaderProgram::setUniform3iv( const std::string& uniformName, GLsizei size, const GLint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3iv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform3ui( const std::string& uniformName, GLuint x, GLuint y, GLuint z )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3ui( _programID, location, x, y, z );
	}
	void ShaderProgram::setUniform3uiv( const std::string& uniformName, GLsizei size, const GLuint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform3uiv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform4d( const std::string& uniformName, GLdouble x, GLdouble y, GLdouble z, GLdouble w )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4d( _programID, location, x, y, z, w );
	}
	void ShaderProgram::setUniform4dv( const std::string& uniformName, GLsizei size, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4dv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform4f( const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4f( _programID, location, x, y, z, w );
	}
	void ShaderProgram::setUniform4fv( const std::string& uniformName, GLsizei size, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4fv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform4i( const std::string& uniformName, GLint x, GLint y, GLint z, GLint w )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4i( _programID, location, x, y, z, w );
	}
	void ShaderProgram::setUniform4iv( const std::string& uniformName, GLsizei size, const GLint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4iv( _programID, location, size, val );
	}
	void ShaderProgram::setUniform4ui( const std::string& uniformName, GLuint x, GLuint y, GLuint z, GLuint w )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4ui( _programID, location, x, y, z, w );
	}
	void ShaderProgram::setUniform4uiv( const std::string& uniformName, GLsizei size, const GLuint* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniform4uiv( _programID, location, size, val );
	}
	void ShaderProgram::setUniformMatrix2dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix2dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix2fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix2fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix2x3dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix2x3dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix2x3fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix2x3fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix2x4dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix2x4dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix2x4fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix2x4fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix3dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix3dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix3fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix3fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix3x2dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix3x2dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix3x2fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix3x2fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix3x4dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix3x4dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix3x4fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix3x4fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix4dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix4dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix4fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix4fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix4x2dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix4x2dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix4x2fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix4x2fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix4x3dv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLdouble* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix4x3dv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setUniformMatrix4x3fv( const std::string& uniformName, GLsizei count, GLboolean transpose, const GLfloat* val )
	{
		auto location = glGetUniformLocation( _programID, uniformName.c_str() );
		_ASSERT( location != -1 );
		glProgramUniformMatrix4x3fv( _programID, location, count, transpose, val );
	}
	void ShaderProgram::setMaterialUniforms( const Material& material, const std::string& strName, const std::string& ambMemName, const std::string& diffMemName, const std::string& specMemName, const std::string& shineMemeName )
	{
		setUniform3f( strName + "." + ambMemName, material.ambient.r, material.ambient.g, material.ambient.b );
		setUniform3f( strName + "." + diffMemName, material.diffuse.r, material.diffuse.g, material.diffuse.b );
		setUniform3f( strName + "." + specMemName, material.specular.r, material.specular.g, material.specular.b );
		setUniform1f( strName + "." + shineMemeName, material.shininess );
	}
	void ShaderProgram::setLightPropUniforms( const LightProperties& prop, const std::string& strName, const std::string& ambMemName, const std::string& diffMemName, const std::string& specMemName )
	{
		setUniform3f( strName + "." + ambMemName, prop.ambient.r, prop.ambient.g, prop.ambient.b );
		setUniform3f( strName + "." + diffMemName, prop.diffuse.r, prop.diffuse.g, prop.diffuse.b );
		setUniform3f( strName + "." + specMemName, prop.specular.r, prop.specular.g, prop.specular.b );
	}
	void ShaderProgram::setAttenuationCoefsUniforms( const LightAttenuationCoefs& coefs, const std::string& strName, const std::string& constMemName, const std::string& linearMemName, const std::string& quadraticMemName )
	{
		setUniform1f( strName + "." + constMemName, coefs.constant );
		setUniform1f( strName + "." + linearMemName, coefs.linear );
		setUniform1f( strName + "." + quadraticMemName, coefs.quadratic );
	}
}