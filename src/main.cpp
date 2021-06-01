#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

static const int DEFAULT_WINDOW_WIDTH = 1280;
static const int DEFAULT_WINDOW_HEIGHT = 720;

int main() {
  // SDL_Init(SDL_INIT_EVENTS);

#ifdef __APPLE__
  // SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS,
  //                     SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  // SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
  // SDL_GL_CONTEXT_PROFILE_CORE);
  // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#endif

  // SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
  // SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  // SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
  // SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  GLFWwindow *window;

  if (!glfwInit()) {
    std::cout << "glfwInit error" << std::endl;
    return -1;
  }

  // SDL_Window *window =
  //     SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED,
  //     SDL_WINDOWPOS_CENTERED,
  //                      DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT,
  //                      SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);

  window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT,
                            "glfw window", NULL, NULL);

  // SDL_GLContext glcontext = SDL_GL_CreateContext(window);
  glewExperimental = GL_TRUE;
  glewInit();

  glfwMakeContextCurrent(window);

  // SDL_GL_MakeCurrent(window, glcontext);
  // SDL_GL_SetSwapInterval(1);
  // glfwSwapInterval(1);

  // glEnable(GL_BLEND);
  // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // SDL_Event event;
  // bool quit = false;
  // while (!quit) {
  //   while (SDL_PollEvent(&event)) {
  //     quit = SDL_QUIT == event.type;
  //   }

  //   SDL_GL_SwapWindow(window);
  // }

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // SDL_GL_DeleteContext(glcontext);
  // SDL_DestroyWindow(window);
  // SDL_Quit();
  glfwTerminate();

  return 0;
}
