#include "Shader.h"

//Aus der Abend OVL
CShader::CShader(const char* a_sVertexPath, const char* a_sFragPath)
{
	std::string vertexCode{};
	std::string fragmentCode{};
	std::fstream vertShaderFile{};
	std::fstream fragShaderFile{};

	vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertShaderFile.open(a_sVertexPath, std::ios::in);
		fragShaderFile.open(a_sFragPath, std::ios::in);

		std::stringstream vertexShaderStream;
		std::stringstream fragShaderStream;

		vertexShaderStream << vertShaderFile.rdbuf();
		fragShaderStream << fragShaderFile.rdbuf();

		vertShaderFile.close();
		fragShaderFile.close();

		vertexCode = vertexShaderStream.str();
		fragmentCode = fragShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << M_S_SHADERFILE_NOT_READ << std::endl;
	}

	const char* vertexShaderCode = vertexCode.c_str();
	const char* fragShaderCode = fragmentCode.c_str();

	unsigned int vertex{};
	unsigned int fragment{};
	int success{};

	char infolog[512]{};

	vertex = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertex, 1, &vertexShaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertex, 512, NULL, infolog);
		std::cout << M_S_SHADER_NOT_COMPILE_VERTEX << std::endl
			<< infolog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragShaderCode, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragment, 512, NULL, infolog);
		std::cout << M_S_SHADER_NOT_COMPILE_FRAGMENT << std::endl
			<< infolog << std::endl;
	}

	m_iID = glCreateProgram();

	glAttachShader(m_iID, vertex);
	glAttachShader(m_iID, fragment);
	glLinkProgram(m_iID);

	glGetProgramiv(m_iID, GL_LINK_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(m_iID, 512, NULL, infolog);
		std::cout << M_S_SHADER_NOT_LINK << std::endl
			<< infolog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void CShader::Use(void)
{
	glUseProgram(m_iID);
}

unsigned int CShader::GetAttributeLocation(const char* a_cName)
{
	return glGetAttribLocation(m_iID, a_cName);
}
