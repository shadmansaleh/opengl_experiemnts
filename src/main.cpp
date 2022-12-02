#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main(){\n"
    "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
    "  FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
    "}\n\0";



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS
        || glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main() {
  // initialize glfw
  glfwInit();

  // specify flags for glfw or modes it'd work in
  // use opengl 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // use core profile so only modern functions
  glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // create a new gl window
  GLFWwindow *window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
  if (window == NULL) { // error check
    std::cout << "Failed to create window" << std::endl;
    glfwTerminate();
    return -1;
  }

  // switch to created window
  glfwMakeContextCurrent(window);

  // load glad so it configures opengl
  gladLoadGL();

  // create a view port that would be displayed in window
  glViewport(0, 0, 800, 800);
  // resize view port when window is resized
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // create shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // create a shader program and link the shaders to it
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // vertices of the triangle
  GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3,    0.0f, // lower left corner
    0.5f,  -0.5f * float(sqrt(3)) / 3,    0.0f, // lower right corner
    0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
    -0.5f/2, 0.5f * float(sqrt(3)) / 6,    0.0f, // Inner left
    0.5f / 2,  0.5f * float(sqrt(3)) / 6,    0.0f, // inner right
    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // inner down
  };

  unsigned int indices[] = {  // note that we start from 0!
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
  };

  // VertexArray and VertexBuffer
  GLuint VAO, VBO, EBO;

  // create vertax bufferArray nd vetex buffer
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  // bind the vertexArray as current vertex array
  glBindVertexArray(VAO);

  // bind vertex buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // attach vertices data to vertexBuffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  // detach the vertex arrays and buffers so they don't get accidentally changed
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // main loop
  while (!glfwWindowShouldClose(window)) {
    processInput(window);
    // set bg color
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // apply shader program
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    // glDrawArrays(GL_TRIANGLES, 0, 3);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    // poll events
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteProgram(shaderProgram);

  // clear window context.
  glfwDestroyWindow(window);
  // clear glfw
  glfwTerminate();
  return 0;
}
