cmake_minimum_required(VERSION 3.31)

project(Lab1 VERSION 1.0
 DESCRIPTION "Subject: Design patterns. First laboratory work."
 LANGUAGES CXX)
 
file(GLOB SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.hpp")
 
add_executable(Lab1
 ${SRCS}
 ${HDRS})

target_include_directories(Lab1 PRIVATE "include/")
