cmake_minimum_required(VERSION 3.22)
project(JIT_compiler)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

include(CheckPIESupported)
check_pie_supported()

SET(OBJS
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/printf.o
        )

SET_SOURCE_FILES_PROPERTIES(
        ${OBJS}
        PROPERTIES
        EXTERNAL_OBJECT true
        GENERATED true
)

add_executable(JIT_compiler
        ${OBJS}
        src/simple_string.cpp
        src/Assembler.cpp
        src/Builder.cpp
        src/BCDict.cpp
        src/Translator.cpp
        main.cpp)
set_property(TARGET JIT_compiler PROPERTY POSITION_INDEPENDENT_CODE FALSE)

target_include_directories(JIT_compiler PUBLIC /home/mikhalinho/CLionProjects/Common)
