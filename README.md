# OpenGLEXP

A simple OpenGL 3.3 experiment project demonstrating basic rendering techniques, including shaders, textures, and vertex buffer management.

## Features

- **OpenGL 3.3 Core Profile**: Uses modern OpenGL practices.
- **Custom Wrapper Classes**: Simplifies management of:
    - Shaders (`Shader` class)
    - Vertex Array Objects (`VAO`)
    - Vertex Buffer Objects (`VBO`)
    - Element Buffer Objects (`EBO`)
    - Textures (`Texture` class)
- **Texture Loading**: Uses `stb_image` to load and display textures (currently featuring a Goku texture).
- **Input Handling**: Basic GLFW input processing (Esc or Q to quit).

## Prerequisites

To build and run this project, you need to have the following installed on your system:

- **C++ Compiler** (supporting C++17)
- **CMake** (version 3.0 or higher) or **Make**
- **GLFW**
- **OpenGL Development Libraries** (e.g., `libgl1-mesa-dev` on Linux)
- **X11 Libraries** (X11, Xrandr, Xi, etc.)

On Ubuntu/Debian, you can install the dependencies with:
```bash
sudo apt-get update
sudo apt-get install build-essential cmake libglfw3-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev
```

## Building and Running

### Using CMake (Recommended)

1. Create a build directory:
   ```bash
   mkdir build && cd build
   ```
2. Generate build files and compile:
   ```bash
   cmake ..
   make
   ```
3. Run the executable:
   ```bash
   ./openGL_exp
   ```

### Using Makefile

Alternatively, you can use the provided Makefile in the root directory:

1. Compile:
   ```bash
   make
   ```
2. Run:
   ```bash
   ./openGL_exp
   ```

## Controls

- **Q / ESC**: Close the window.

## Project Structure

- `include/`: Header files for the custom wrapper classes.
- `src/`: Implementation files.
- `libraries/`: External dependencies (GLAD, stb_image).
- `resources/`: Shaders and textures.
    - `resources/shaders/`: Vertex and Fragment shaders.
    - `resources/textures/`: Texture images.

## License

This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE) file for details.
