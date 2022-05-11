cmake_minimum_required(VERSION 3.22)
project(JIT_compiler)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(JIT_compiler
        src/simple_string.cpp
        src/Assembler.cpp
        src/Builder.cpp
        src/BCDict.cpp
        src/Translator.cpp
        main.cpp)

target_include_directories(JIT_compiler PUBLIC /home/mikhalinho/CLionProjects/Common)
