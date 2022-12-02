#ifndef VAO_CLASS_HPP
#define VAO_CLASS_HPP

#include "glad/glad.h"
#include "VBO.hpp"

class VAO
{
  public:
    // reference to the vertex array obj
    GLuint ID;
    // generates a vao obj
    VAO();

    // links vb to a layout
    void LinkAtrib(VBO vb, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* ofset);
    void Bind();
    void Unbind();
    void Delete();
};
#endif // !VAO_CLASS_HPP
