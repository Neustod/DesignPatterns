cmake_minimum_required(VERSION 3.15...3.31)

project(Lab1 VERSION 1.0
 DESCRIPTION "Subject: Design patterns. First laboratory work."
 LANGUAGES CXX)
 
file(GLOB SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")
 
add_executable(Lab1
 ${SOURCES}
 ${HEADERS})

target_include_directories(Lab1 PUBLIC "include/")