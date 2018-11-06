# Bubble sort
project(bubblesort)

# Create executable
add_executable(${PROJECT_NAME} bubble.cpp)

# Link require library
target_link_libraries(${PROJECT_NAME}
  PUBLIC bigsortlib
)