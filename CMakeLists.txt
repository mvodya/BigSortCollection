# Big sort collection - main СMake lists
project(bigsortcollection)

# Minimum CMake version
cmake_minimum_required(VERSION 3.4)

# Add main library
add_subdirectory(big-sort-lib)

# Add projects
add_subdirectory(bubble-sort)