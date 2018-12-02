# Big sort collection - main СMake lists
project(bigsortcollection)

# Minimum CMake version
cmake_minimum_required(VERSION 3.4)

# Add main library
add_subdirectory(big-sort-lib)

# Add projects
add_subdirectory(bubble-sort)
add_subdirectory(insertion-sort)
add_subdirectory(cocktail-sort)
add_subdirectory(merge-sort)
add_subdirectory(quick-sort)