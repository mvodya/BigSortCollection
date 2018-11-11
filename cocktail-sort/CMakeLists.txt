# Cocktail sort
project(cocktailsort)

# Create executable
add_executable(${PROJECT_NAME} cocktail.cpp)

# Link require library
target_link_libraries(${PROJECT_NAME}
  PUBLIC bigsortlib
)