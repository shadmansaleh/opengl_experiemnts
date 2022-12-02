#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaderClass.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

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

  // vertices of the triangle
  GLfloat vertices[] = {
    //     Co-ordinates                          Colors
   -0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f,  0.8f, 0.3f, 0.02f, // lower left corner
    0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f, 0.8f, 0.3f, 0.02f,  // lower right corner
    0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f, 1.0f, 0.6f, 0.32f,  // upper corner
   -0.25f, 0.5f * float(sqrt(3)) / 6,     0.0f, 0.9f, 0.45f, 0.17f, // Inner left
    0.25f, 0.5f * float(sqrt(3)) / 6,     0.0f, 0.9f, 0.45f, 0.17f, // inner right
    0.0f, -0.5f * float(sqrt(3)) / 3,     0.0f, 0.8f, 0.3f, 0.02f   // inner down
  };

  unsigned int indices[] = {  // note that we start from 0!
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
  };

  // generate shader object from vertex and fragment shader files
  Shader shaderProgram("./resources/shaders/default.vert",
                       "./resources/shaders/default.frag");

  // generate vertax array obj and bind it
  VAO VAO1;
  VAO1.Bind();

  // generate vertex buffer and element buffers
  VBO VBO1(vertices, sizeof(vertices));
  EBO EBO1(indices, sizeof(indices));

  VAO1.LinkAtrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
  VAO1.LinkAtrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

  VAO1.Unbind();
  VBO1.Unbind();
  EBO1.Unbind();

  GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // main loop
  while (!glfwWindowShouldClose(window)) {
    processInput(window);
    // set bg color
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // apply shader program
    shaderProgram.Activate();
    glUniform1f(uniID, 0.5f);
    VAO1.Bind();
    // glDrawArrays(GL_TRIANGLES, 0, 3);

    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
    VAO1.Unbind();
    glfwSwapBuffers(window);
    // poll events
    glfwPollEvents();
  }

  VAO1.Delete();
  VBO1.Delete();
  EBO1.Delete();
  shaderProgram.Delete();

  // clear window context.
  glfwDestroyWindow(window);
  // clear glfw
  glfwTerminate();
  return 0;
}
