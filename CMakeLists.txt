cmake_minimum_required(VERSION 3.7)
project(krLIB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        krLIB/Array.cpp
        krLIB/Array.h
        krLIB/BinaryTree.cpp
        krLIB/BinaryTree.h
        krLIB/cstring.cpp
        krLIB/cstring.h
        krLIB/List.cpp
        krLIB/List.h
        krLIB/main.cpp
        krLIB/Queue.cpp
        krLIB/Queue.h
        krLIB/Stack.cpp
        krLIB/Stack.h
        krLIB/String.cpp
        krLIB/String.h
        krLIB.sln)

add_executable(krLIB ${SOURCE_FILES})