#include "Viewport.h"

CViewport::CViewport(const int& a_iHeight, const int& a_iWidth, const std::string& a_sTitle)
	: m_iHeight(a_iHeight), m_iWidth(a_iWidth), m_sTitle(a_sTitle) {}

const bool CViewport::ShouldWindowClose(void) const
{
	return glfwWindowShouldClose(m_pWindow);
}

void CViewport::Initialize(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, M_I_CONTEXT_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, M_I_CONTEXT_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	m_pWindow = glfwCreateWindow(720, 580, m_sTitle.c_str(), nullptr, nullptr);
	if (m_pWindow == nullptr) {
		std::cout << M_S_FAILED_TO_CREATE_WINDOW << M_C_WORDWRAP;
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_pWindow);
	//Mit Marcus Schaal zusammen im OCE/Practical Programming gemacht
	auto frameBufferSizeLambda = [](GLFWwindow* a_pWindow, int a_iWidth, int a_iHeight) {
		glViewport(0, 0, a_iWidth, a_iHeight);
		};
	glfwSetFramebufferSizeCallback(m_pWindow, frameBufferSizeLambda);

	//Ab hier wieder alleine
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << M_S_FAILED_TO_INITIALIZE_GLAD << M_C_WORDWRAP;
	}

}

void CViewport::Update(void)
{
	if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(m_pWindow, true);
	}
}

void CViewport::Draw(void)
{

	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(m_pWindow);
}

void CViewport::Finalize(void)
{
	glfwTerminate();
}
