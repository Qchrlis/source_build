cmake_minimum_required(VERSION 2.8)

project(source_build)

file(GLOB SRC "*.cpp")
add_executable(${PROJECT_NAME} ${SRC} "main.cpp")
