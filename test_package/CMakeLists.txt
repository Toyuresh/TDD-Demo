cmake_minimum_required(VERSION 2.8.12)
project(PackageTest CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(GTest REQUIRED)
if (NOT GTEST_FOUND)
    message(FATAL_ERROR "Could not find GTest")
endif()

if(WITH_GMOCK)
    find_package(GMock REQUIRED)
    if (NOT GMOCK_FOUND)
        message(FATAL_ERROR "Could not find GMock")
    endif()
endif()

add_executable(example example.cpp CharUtilTest.cpp StringUtilTest.cpp)
target_link_libraries(example ${CONAN_LIBS})


# CTest is a testing tool that can be used to test your project.
 enable_testing()
 add_test(NAME example
          WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
          COMMAND example)
