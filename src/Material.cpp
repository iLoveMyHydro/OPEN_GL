#include "Material.h"

void CMaterial::Initialize(CShader* a_pShader)
{
	m_pShader = a_pShader;
}

void CMaterial::Draw()
{
	m_pShader->Use();
}
