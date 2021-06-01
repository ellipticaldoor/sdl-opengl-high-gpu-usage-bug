cmake_minimum_required (VERSION 3.17.2)
project(gputest)

set(CMAKE_BUILD_TYPE "Release")

include(GNUInstallDirs)

find_package(GLEW 2.0 REQUIRED)

include_directories("include")

IF(APPLE)
  include_directories("/usr/local/include")
  set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
ENDIF()

set(GAME_MAIN ${PROJECT_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${GAME_MAIN})

IF(APPLE)
  find_library(COREVIDEO NAMES CoreVideo)
  find_library(IOKIT NAMES IOKit)
  find_library(COCOA NAMES Cocoa)
  SET(GLFW3_LIBRARIES ${GLFW3_LIBRARIES} ${COREVIDEO} ${IOKIT} ${COCOA})
  set(GLFW3 ${PROJECT_SOURCE_DIR}/lib/macos/lib-universal/libglfw3.a)

  execute_process(
    COMMAND pkg-config --cflags --libs sdl2 sdl2_mixer
    OUTPUT_VARIABLE SDL_CXX_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  target_link_libraries(${PROJECT_NAME} ${GLFW3_LIBRARIES} ${GLFW3} ${SDL_CXX_FLAGS} GLEW::GLEW)
ENDIF()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set(COMPILE_OPTIONS_FLAGS
  -O2
  -Wall
  -Wextra
  -Werror
  -Wno-error=unused
  -Wpedantic
  -Wdouble-promotion
  -Woverloaded-virtual
  -Wnull-dereference
  -Wformat=2
  -Wundef
  -Wconversion
  -Wfatal-errors
  -Wshadow
  -Wmissing-noreturn
  -Wunreachable-code
  -Wno-c99-extensions
  -Wno-gnu-zero-variadic-macro-arguments
  -Werror=return-type
  -Iinclude
  -fno-common
)

target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS_FLAGS})
