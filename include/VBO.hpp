#ifndef VERTEX_BUFFER_CLASS_HPP
#define VERTEX_BUFFER_CLASS_HPP

#include "glad/glad.h"

class VBO
{
  public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);

    void Bind();
    void Unbind();
    void Delete();
};
#endif // !VERTEX_BUFFER_CLASS_HPP
