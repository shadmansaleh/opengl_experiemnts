#ifndef EBO_CLASS_HPP
#define EBO_CLASS_HPP

#include "glad/glad.h"

class EBO
{
  public:
    GLuint ID;
    EBO(unsigned int* indices, GLsizeiptr size);

    void Bind();
    void Unbind();
    void Delete();
};
#endif // !EBO_CLASS_HPP
