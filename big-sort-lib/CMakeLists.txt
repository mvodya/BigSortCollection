# Big sort library - СMake lists
project (bigsortlib)

# Library sources
set(SRC 
"src/visualm.cpp"
"include/bigsortlib/visualm.h")

add_library(${PROJECT_NAME} ${SRC})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Set C++17 standart
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

# Require GLFW library
find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)
# Require OpenGL
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
