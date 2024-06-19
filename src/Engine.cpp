#include "Engine.h"

CEngine::CEngine() : m_pViewport(new CViewport(M_I_WIDTH, M_I_HEIGHT, M_S_ENGINE_NAME)), m_pMesh(new CMesh()) {}

CEngine::~CEngine(void)
{
	if (m_pShaderProgram != nullptr)
	{
		delete m_pShaderProgram;
		m_pShaderProgram = nullptr;
	}

	if (m_pMesh != nullptr) {
		delete m_pMesh;
		m_pMesh = nullptr;
	}

	if (m_pViewport != nullptr) {
		delete m_pViewport;
		m_pViewport = nullptr;
	}
}

void CEngine::Initialize(void)
{
	std::cout << M_S_INIT << M_C_WORDWRAP;

	if (m_pViewport != nullptr) m_pViewport->Initialize();

	m_pShaderProgram = new CShader("../resource/Vertex.glsl", "../resource/Fragment.glsl");

	if (m_pMesh != nullptr) m_pMesh->Init(m_pShaderProgram);
}

void CEngine::Run(void)
{
	std::cout << M_S_RUN << M_C_WORDWRAP;

	if (m_pViewport == nullptr) return;

	while (!m_pViewport->ShouldWindowClose()) {

		if (m_pViewport != nullptr) m_pViewport->Update();
		if (m_pMesh != nullptr) m_pMesh->Update();

		if (m_pViewport != nullptr) m_pViewport->Draw();
		if (m_pMesh != nullptr) m_pMesh->Draw();

		glfwPollEvents();
	}
}

void CEngine::Finalize(void)
{
	std::cout << M_S_FINALIZE << M_C_WORDWRAP;
	m_pMesh->Finalize();
	m_pViewport->Finalize();
}
