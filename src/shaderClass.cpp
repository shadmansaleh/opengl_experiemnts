#include "shaderClass.hpp"
#include "cstring"

std::string get_file_contents(const char* filename)
{
  std::ifstream in(filename, std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return contents;
  }
  throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) 
{
  std::string vertexCode = get_file_contents(vertexFile);
  std::string fragmentCode = get_file_contents(fragmentFile);
  const char* vertexShderSource = vertexCode.c_str();
  const char* fragmentShaderSource = fragmentCode.c_str();
  // create shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShderSource, NULL);
  glCompileShader(vertexShader);
  compileErrors(vertexShader, "VERTEX");

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  compileErrors(fragmentShader, "FRAGMENT");

  // create a shader program and link the shaders to it
  ID = glCreateProgram();
  glAttachShader(ID, vertexShader);
  glAttachShader(ID, fragmentShader);
  glLinkProgram(ID);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
  // apply shader program
  glUseProgram(ID);
}
void Shader::Delete()
{
  glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char *type)
{
  GLint hasCompiled;
  char infoLog[1024];
  // if (strcmp(type, "PROGRAM") == 0)
  // {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
    if (hasCompiled == GL_FALSE) 
    {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      std::cout << "Shader Compile Error for: " << type << " => " << infoLog << std::endl;
    // }
  }
}
