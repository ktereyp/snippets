find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
add_library(native SHARED ./HelloWorld.cpp)
