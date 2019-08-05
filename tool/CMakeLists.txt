
set(EARSRC capture_entry.cpp
  capture_handle.cpp)

add_executable(ear_handle ${EARSRC})


set(BUILDSRC capture_build.cpp)

add_executable(src_build ${BUILDSRC})
