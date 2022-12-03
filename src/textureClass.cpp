#include "textureClass.hpp"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
  type = texType;

  int widthImg, heightImg, numColCh;
  // flip the image on load because stbi loads from top an opengl loads from bottom
  stbi_set_flip_vertically_on_load(true);
  // load image from file
  unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

  // generate, bind and activate texture
  glGenTextures(1, &ID);
  glActiveTexture(slot); // there are limited texture slots
  glBindTexture(texType, ID);

  // set how texture will get scaled
  glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // set how texture will be tiled
  glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

  /* // needed when placing solid borders instead of tiling
   * float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
   * glTexParameteri(texType, GL_TEXTURE_BORDER_COLOR, flatColor);
   */

  // generate texture from the image
  glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
  // generate mipmap from texutre. these are low res images that are used while actuall image is being loaded. say like thumbnail
  glGenerateMipmap(texType);

  // remove image data. we don't need it after creating texture
  stbi_image_free(bytes);
  // unbind texture
  glBindTexture(slot, 0);
}

void Texture::texUnit(Shader shader, const char* uniform, GLuint unit) {
  // place texture location on a uniform so fragment shader can access it.
  GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
  shader.Activate();
  glUniform1i(tex0Uni, unit);
}
void Texture::Bind() {
  glBindTexture(type, ID);
}
void Texture::Unbind() {
  glBindTexture(type, 0);
}
void Texture::Delete() {
  glDeleteTextures(1, &ID);
}
