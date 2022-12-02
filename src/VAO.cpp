#include "VAO.hpp"

VAO::VAO()
{
  glGenVertexArrays(1, &ID);
}

void VAO::LinkAtrib(VBO vb, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* ofset)
{
  vb.Bind();
  glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, ofset);
  glEnableVertexAttribArray(layout);
  vb.Unbind();
}

void VAO::Bind()
{
  glBindVertexArray(ID);
}
void VAO::Unbind()
{
  glBindVertexArray(0);
}

void VAO::Delete()
{
  glDeleteVertexArrays(1, &ID);
}
