cmake_minimum_required(VERSION 2.8)
project(MyHello CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(hello Soundex.cpp CharUtil.cpp StringUtil.cpp) 

add_executable(test main.cpp)
target_link_libraries(test hello)
