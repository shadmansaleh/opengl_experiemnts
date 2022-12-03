#ifndef UTILS_HPP
#define UTILS_HPP

#define EXIT_ON_ERROR
#include <glad/glad.h>
GLenum glCheckError_(const char *file, int line);

#ifndef GL_NO_ERROR_CHECK
#define GLE() glCheckError_(__FILE__, __LINE__);
#else
#define GLE()
#endif

#endif // !UTILS_HPP
