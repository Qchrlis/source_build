cmake_minimum_required(VERSION 2.8)

project(source_build)

include_directories(${source_build_SOURCE_DIR}/include
  ${source_build_SOURCE_DIR}/include/src
  ${source_build_SOURCE_DIR}/include/utils
  ${source_build_SOURCE_DIR}/include/lib
  ${source_build_SOURCE_DIR}/include/tool)


add_subdirectory(src)
add_subdirectory(utils)
add_subdirectory(lib)
add_subdirectory(tool)
