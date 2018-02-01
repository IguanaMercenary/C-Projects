cmake_minimum_required(VERSION 3.9)
project(BST C)

set(CMAKE_C_STANDARD 11)

add_executable(BST main.c BSTDelete.c BSTDelete.h BSTStruct.h BSTMinMax.c BSTMinMax.h orderTraversal.c orderTraversal.h)