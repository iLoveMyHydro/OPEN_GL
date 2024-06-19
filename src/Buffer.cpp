#include "Buffer.h"

#include <iostream>

void CBuffer::CreateBufferObject()
{
	glGenBuffers(1, &m_uiBufferID);
}

void CBuffer::SetAttributeID(const char* a_cName, unsigned int a_uiID)
{
	m_uiAttributeID = a_uiID;
	if(m_uiAttributeID == -1)
	{
		std::cout << a_cName << ": Attribute does not exist" << std::endl;
	}
}

void CBuffer::Bind(GLenum a_eTarget)
{
	m_eTarget = a_eTarget;
	glBindBuffer(m_eTarget, m_uiBufferID);
}

void CBuffer::BufferFill(GLsizeiptr a_liSize, const void* a_pData, GLenum a_eUsage)
{
	glBufferData(m_eTarget, a_liSize, a_pData, a_eUsage);
}

void CBuffer::LinkAttribute(unsigned int a_uiSize, GLenum a_eType, bool a_bNormalized, GLsizei a_iStride, const void* a_pOffset)
{
	glVertexAttribPointer(m_uiAttributeID, a_uiSize, a_eType, a_bNormalized, a_iStride, a_pOffset);
	glEnableVertexAttribArray(m_uiAttributeID);
}

void CBuffer::Finalize()
{
	glDeleteBuffers(1, &m_uiBufferID);
}
