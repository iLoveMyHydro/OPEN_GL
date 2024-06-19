#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

//Aus der Abend OVL
class CShader
{
public:
	inline CShader() {};

	CShader(const char* a_sVertexPath, const char* a_sFragPath);

	void Use(void);
	unsigned int GetAttributeLocation(const char* a_cName);

private:
	unsigned int m_iID = 0;
	const std::string M_S_SHADERFILE_NOT_READ = std::string("Failed to read the Shaderfile");
	const std::string M_S_SHADER_NOT_COMPILE_VERTEX = std::string("Failed to compile Vertex Shader");
	const std::string M_S_SHADER_NOT_COMPILE_FRAGMENT = std::string("Failed to compile Fragment Shader");
	const std::string M_S_SHADER_NOT_LINK = std::string("Failed to Link Shader");
};

#endif // !SHADER_H