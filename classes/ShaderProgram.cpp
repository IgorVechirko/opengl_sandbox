#include "ShaderProgram.h"



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

}