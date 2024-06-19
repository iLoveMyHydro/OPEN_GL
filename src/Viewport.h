#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class CViewport
{
public:
	CViewport(const int& a_iHeight, const int& a_iWidth, const std::string& a_sTitle);

	//Getter/Setter
	const bool ShouldWindowClose(void) const;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

private:

#pragma region Constants

	const int M_I_CONTEXT_VERSION_MAJOR = 4;
	const int M_I_CONTEXT_VERSION_MINOR = 6;
	const float M_S_RED_COLOR = 1.0f;
	const float M_S_GREEN_COLOR = 0.0f;
	const float M_S_BLUE_COLOR = 0.0f;
	const float M_S_ALPHA_VALUE = 1.0f;
	const std::string m_sTitle = std::string("Hydro Engine");
	const std::string M_S_FAILED_TO_CREATE_WINDOW = std::string("Failed to create the window");
	const std::string M_S_FAILED_TO_INITIALIZE_GLAD = std::string("Failed to initialize GLAD");
	const std::string M_S_VERTEXPATH = std::string("Vertex.glsl");
	const std::string M_S_FRAGPATH = std::string("Fragment.glsl");
	const GLint M_I_SIZE = 3;
	const GLint M_I_ZERO = 0;
	const GLint M_I_IDX = 0;
	const GLint M_I_BUFFER_SIZE = 1;
	const GLint M_I_POSITION_INDEX = 0;
	const GLint M_I_EMPTY = 0;
	const GLint M_I_FIRST = 0;
	const GLint M_I_COUNT = 4;
	const char M_C_WORDWRAP = '\n';

#pragma endregion

	std::int32_t m_iWidth, m_iHeight;
	struct GLFWwindow* m_pWindow = nullptr;
		CShader* m_shaderProgram = nullptr;

};

#endif // !VIEWPORT_H