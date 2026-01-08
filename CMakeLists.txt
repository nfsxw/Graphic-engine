cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME GraphicEngine)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/glad.c
)

target_include_directories(GraphicEngine PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    OpenGL::GL
)