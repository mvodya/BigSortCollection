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