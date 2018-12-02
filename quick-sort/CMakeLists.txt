# Quick sort
project(quicksort)

# Create executable
add_executable(${PROJECT_NAME} quick.cpp)

# Link require library
target_link_libraries(${PROJECT_NAME}
  PUBLIC bigsortlib
)