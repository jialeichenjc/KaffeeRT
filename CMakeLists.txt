cmake_minimum_required(VERSION 3.10)

project(KaffeeRT VERSION 1.0)

message(${CMAKE_CURRENT_BINARY_DIR})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

set(googletest-srcdir ${CMAKE_CURRENT_BINARY_DIR}/googletest-src/googletest)

set(SOURCES 
    main.cpp
    Vec.h
    Vec.cpp
    Draw.h
    Mat.h
    Mat.cpp
    TestDraw.h
    TestVec4.h
    TestMat.h
    TestTransformation.h
    AllTests.h
    ${googletest-srcdir}/include/gtest/gtest.h)

add_executable(KaffeeRT ${SOURCES})
target_link_libraries(KaffeeRT gtest_main)
target_include_directories(KaffeeRT PRIVATE ${googletest-srcdir})
add_test(NAME example_test COMMAND KaffeeRT)
