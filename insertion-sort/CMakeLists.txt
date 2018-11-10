# Insertion sort
project(insertionsort)

# Create executable
add_executable(${PROJECT_NAME} insertion.cpp)

# Link require library
target_link_libraries(${PROJECT_NAME}
  PUBLIC bigsortlib
)