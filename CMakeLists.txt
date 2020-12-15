cmake_minimum_required(VERSION 3.16)
project(cpp_programming)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-fsanitize=address -g -Wall -Werror")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
#2 Contest Cats
#add_executable(cpp_programming 2Cats/FixedAllocator/main.cpp 2Cats/FixedAllocator/fixed_allocator.h)
#add_executable(cpp_programming 2Cats/FormatVisitor/main.cpp)
#add_executable(cpp_programming 2Cats/Fabric/main.cpp 2Cats/Fabric/factory.h)
#add_executable(cpp_programming 2Cats/SmartPointer/main.cpp 2Cats/SmartPointer/SmartPointer.hpp 2Cats/SmartPointer/Test.hpp 2Cats/SmartPointer/Test_SmartPointer.hpp)
#add_executable(cpp_programming 2Cats/GameDatabase/main.cpp)

#3 Contest Cats
#add_executable(cpp_programming 3Cats/Initialize_vector/main.cpp 3Cats/Initialize_vector/initialize_vector.h)
#add_executable(cpp_programming 3Cats/Binary-linear-search/main.cpp 3Cats/Binary-linear-search/find.h)
#add_executable(cpp_programming 3Cats/Is-convertable/main.cpp 3Cats/Is-convertable/is_customly_convertible.h)
add_executable(cpp_programming 3Cats/Graph-visitor/main.cpp 3Cats/Graph-visitor)