#ifndef TEXTURE_CLASS_HPP
#define TEXTURE_CLASS_HPP

#include <glad/glad.h>
#include <stb/stb_image.h>
#include "shaderClass.hpp"

class Texture {
  public:
    GLuint ID;
    GLenum type;
    // load a texture from image
    Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    // mark the texture slot on a uniform so fragment shader can pick it up
    void texUnit(Shader shader, const char* uniform, GLuint unit);
    void Bind();
    void Unbind();
    void Delete();
};
#endif // !TEXTURE_CLASS_HPP
