# Merge sort
project(mergesort)

# Create executable
add_executable(${PROJECT_NAME} merge.cpp)

# Link require library
target_link_libraries(${PROJECT_NAME}
  PUBLIC bigsortlib
)