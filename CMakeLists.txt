cmake_minimum_required(VERSION 3.10)

project(Decaff)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ldl -lfl")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_FLEX_BISON_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/flex_bison_output)

# Create the directory for flex and bison outputs
file(MAKE_DIRECTORY ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})

# Setup the required Libraries
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
find_package(BISON)
find_package(FLEX)

# Link the directories which contain required libraries
# link_directories(/usr/lib/llvm-6.0/build/lib)

# Add directories which has the header files that are used in the project
# include_directories(/usr/lib/llvm-6.0/build/include)
include_directories(src)
# include_directories(src/class_definitions)

# Make Lexical analyser and parser using flex and bison
BISON_TARGET(Parser src/decaff.ypp ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/decaff.tab.cpp)
FLEX_TARGET(Lexer src/decaff.l ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/lex.yy.cc)


# Build the core functionality shared library
# add_library(coreLibrary SHARED)

# Add the main executable
add_executable(decaff
        ${FLEX_Lexer_OUTPUTS}
        ${BISON_Parser_OUTPUTS})
target_include_directories(decaff PRIVATE
        ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})
# target_link_libraries(decaff coreLibrary)

# llvm_map_components_to_libnames(llvm_libs support core irreader mcjit native)
# target_link_libraries(decafCompiler ${llvm_libs})