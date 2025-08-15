cmake_minimum_required(VERSION 3.16)
project(Simple3DRenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(src)

# Source files
set(SOURCES
    src/main.cpp
    src/math/Vector3.cpp
    src/math/Matrix4.cpp
    src/renderer/Camera.cpp
    src/renderer/Renderer.cpp
    src/geometry/Mesh.cpp
    src/geometry/Primitives.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Compiler flags
target_compile_options(${PROJECT_NAME} PRIVATE ${SDL2_CFLAGS_OTHER})
