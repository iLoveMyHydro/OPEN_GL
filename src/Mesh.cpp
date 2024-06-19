#include "Mesh.h"

void CMesh::Init(CShader* a_pShader)
{
	m_vVertices = {
							//aPosition							//aColor
		{{-0.5f,-0.5f,0.0f}, {0.0f,0.5f,0.1f, 1.0f}},
		{{-0.5f, 0.5f, 0.0f}, {1.0f, 0.5f, 0.1f, 1.0f}},
		{{0.5f, 0.5f, 0.0f}, {0.5f, 0.5f, 0.1f, 1.0f}},
		{{0.5f, -0.5f, 0.0f}, {0.0f, 0.5f, 1.0f, 1.0f}},
	};

	m_vIndices = { 0,1,2,0,2,3 };

	m_pShader = a_pShader;

	CreateBuffers();
}

void CMesh::Update()
{
	return;
}

void CMesh::Draw()
{
	m_pShader->Use();
	glBindVertexArray(m_uiVao);
	glDrawElements(GL_TRIANGLES, m_vIndices.size(), GL_UNSIGNED_INT, 0);
}

void CMesh::Finalize()
{
}

void CMesh::CreateBuffers()
{
	glGenVertexArrays(1, &m_uiVao);
	glBindVertexArray(m_uiVao);

	m_VertexBuffer.CreateBufferObject();
	m_VertexBuffer.Bind(GL_ARRAY_BUFFER);
	m_VertexBuffer.BufferFill(sizeof(SVertex) * m_vVertices.size(), &m_vVertices.front(), GL_STATIC_DRAW);

	const char* a_cAttributeName = "aPosition";
	unsigned int a_uiAttributeID = m_pShader->GetAttributeLocation(a_cAttributeName);
	m_VertexBuffer.SetAttributeID(a_cAttributeName, a_uiAttributeID);
	m_VertexBuffer.LinkAttribute(3, GL_FLOAT, false, sizeof(SVertex), 0);

	m_IndexBuffer.CreateBufferObject();
	m_IndexBuffer.Bind(GL_ELEMENT_ARRAY_BUFFER);
	m_IndexBuffer.BufferFill(sizeof(unsigned int) * m_vIndices.size(), &m_vIndices.front(), GL_STATIC_DRAW);

	glBindVertexArray(0);
}
