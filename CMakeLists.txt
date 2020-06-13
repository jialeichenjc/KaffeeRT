cmake_minimum_required(VERSION 3.10)

project(KaffeeRT VERSION 1.0)

message(${CMAKE_CURRENT_SOURCE_DIR})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(sourceDir ${CMAKE_CURRENT_SOURCE_DIR})
#set(buildDir sourceDir/build)

add_executable(KaffeeRT main.cpp)
