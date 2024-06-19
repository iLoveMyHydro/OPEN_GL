#ifndef ENGINE_H
#define ENGINE_H

#include "Mesh.h"
#include "Viewport.h"
#include <string>
#include <vector>

class CEngine
{
public:

	CEngine(void);
	~CEngine(void);

	void Initialize(void);
	void Run(void);
	void Finalize(void);

private:

#pragma region Constant

	const std::int32_t M_I_HEIGHT = 580;
	const std::int32_t M_I_WIDTH = 720;
	const char M_C_WORDWRAP = '\n';
	const std::string M_S_ENGINE_NAME = std::string("Hydro Engine");
	const std::string M_S_VERTEX_PATH = std::string("../resource/Vertex.glsl");
	const std::string M_S_FRAGMENT_PATH = std::string("../resource/Fragment.glsl");
	const std::string M_S_INIT = std::string("--INIT--");
	const std::string M_S_RUN = std::string("--RUN--");
	const std::string M_S_FINALIZE = std::string("--FINALIZE--");

#pragma endregion

	std::vector<SVertex> m_vVertices;
	struct GLFWwindow* m_pWindow = nullptr;
	class CViewport* m_pViewport = nullptr;
	class CMesh* m_pMesh = nullptr;
	CShader* m_pShaderProgram = nullptr;
};

#endif // !ENGINE_H