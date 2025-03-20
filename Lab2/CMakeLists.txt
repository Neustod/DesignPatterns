cmake_minimum_required(VERSION 3.31)

project(Lab1 VERSION 1.0
 DESCRIPTION "Subject: Design patterns. Second laboratory work."
 LANGUAGES CXX)

file(GLOB SRCS "src/*.cpp")
 
add_executable(Lab2
 ${SRCS}
 )

target_include_directories(Lab2 PRIVATE "${CMAKE_SOURCE_DIR}/include/")
