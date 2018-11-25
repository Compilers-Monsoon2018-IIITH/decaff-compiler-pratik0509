cmake_minimum_required(VERSION 3.10)

project(Decaff)
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -lLLVM-7.0.0 -ldl -lfl")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS} -lLLVM-7.0.0 -ldl -lfl -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -lLLVM-7.0.0 -ldl -lfl -D__TEST")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_FLEX_BISON_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/flex_bison_output)

# Create the directory for flex and bison outputs
file(MAKE_DIRECTORY ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})

# Setup the required Libraries
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM: ${LLVM_INCLUDE_DIRS} ${LLVM_LIBRARY_DIRS} ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
find_package(BISON)
find_package(FLEX)

set(BISON_FLAGS "-v --debug")
# Link the directories which contain required libraries
link_directories(/usr/lib)

# Add directories which has the header files that are used in the project
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(src)
include_directories(src/headers)

# Make Lexical analyser and parser using flex and bison
BISON_TARGET(Parser src/decaff.ypp ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/decaff.tab.cpp COMPILE_FLAGS "-v")
FLEX_TARGET(Lexer src/decaff.l ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/lex.yy.cc)


# Build the core functionality shared library
add_library(coreLibrary SHARED
                src/program.cpp
                src/global_decl.cpp
                src/field_decls.cpp
                src/method_decls.cpp
                src/identifier_list.cpp
                src/identifier.cpp
                src/block.cpp
                src/executables.cpp
                src/var_decl.cpp
                src/binary_op.cpp
                src/literal.cpp
                src/expression.cpp
                src/location.cpp
                src/method_call.cpp
                src/unary_op.cpp
                src/arg_list.cpp
                src/statement.cpp
                src/assignment.cpp
                src/param_list.cpp
                src/for.cpp
                src/if_else.cpp
                src/codegenerator.cpp
        )

# Add the main executable
add_executable(decaff
        ${FLEX_Lexer_OUTPUTS}
        ${BISON_Parser_OUTPUTS})
target_include_directories(decaff PRIVATE
        ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})
target_link_libraries(decaff coreLibrary)

# llvm_map_components_to_libnames(llvm_libs support core irreader mcjit native)
# target_link_libraries(decafCompiler ${llvm_libs})
