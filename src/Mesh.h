#ifndef MESH_H
#define MESH_H
#include <vector>

#include "Buffer.h"
#include "Shader.h"
#include "SVertex.h"

class CMesh
{
public:
	void Init(CShader* a_pShader);

	void Update(void);
	void Draw(void);
	void Finalize(void);

private:
	void CreateBuffers();

private:
	std::vector<SVertex> m_vVertices {};
	std::vector<unsigned int> m_vIndices{};

	CShader* m_pShader = nullptr;

	CBuffer m_VertexBuffer{}, m_IndexBuffer{};
	unsigned int m_uiVao{};
};

#endif