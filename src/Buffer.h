#ifndef BUFFER_H
#define BUFFER_H
#include <glad/glad.h>

//Aus der Abend OVL
class CBuffer
{
public:
	void CreateBufferObject(void);
	void SetAttributeID(const char*, unsigned int);
	void Bind(GLenum);
	void BufferFill(GLsizeiptr, const void*, GLenum);
	void LinkAttribute(unsigned int, GLenum, bool, GLsizei, const void*);
	void Finalize(void);

private:
	unsigned int m_uiBufferID{}, m_uiAttributeID{};
	GLenum m_eTarget;
};

#endif