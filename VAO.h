#ifndef VAO_CLASS_H
#define VAO_CLASS_H
//vertex array class
#include <glad/glad.h>
#include "VBO.h"
//need to link vbo to vao
class VAO
{
public:
	GLuint ID;
	VAO();

	void LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();

};

#endif

