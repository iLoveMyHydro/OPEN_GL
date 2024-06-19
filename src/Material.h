#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include "Shader.h"

//Aus der Abend OVL
class CMaterial
{

public:
	void Initialize(CShader* a_pShader);
	void Draw(void);



private:
	glm::vec3 ambient{1.0f, 1.0f, 1.0f};
	glm::vec3 specular{ 1.0f, 1.0f, 1.0f };
	glm::vec3 diffuse{ 1.0f, 1.0f, 1.0f };
	float shininess{1.0f};
	CShader* m_pShader = nullptr;
	unsigned int m_uiMatAmbientID{}, m_uiMatDiffID{}, m_uiMatSpecID{}, m_uiShinyID{};
	

};

#endif