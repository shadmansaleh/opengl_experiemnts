cmake_minimum_required(VERSION 3.0)
project(OpenGLEXP)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
  "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
  "-fsanitize=address"
  "$<$<CONFIG:DEBUG>:-O0;-gdwarf-4;-ggdb>"
)

add_link_options(-fsanitize=address)

include_directories(./include)
include_directories(./libraries/include)
link_directories(./libraries/lib)

file(GLOB SRC_OPENGL_EXP
  "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB SRC_GLAD
  "${PROJECT_SOURCE_DIR}/libraries/src/glad/*.c")
file(GLOB SRC_SDB
  "${PROJECT_SOURCE_DIR}/libraries/src/stb/*.cpp")

add_executable(openGL_exp ${SRC_OPENGL_EXP} ${SRC_GLAD} ${SRC_SDB})
target_link_libraries(openGL_exp GL glfw X11 pthread Xrandr Xi dl)
