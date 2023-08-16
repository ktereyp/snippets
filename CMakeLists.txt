cmake_minimum_required(VERSION 3.24)
project(snippets)

set(CMAKE_CXX_STANDARD 17)

# boost
find_package(Boost COMPONENTS
        serialization
        filesystem
        unit_test_framework)

# openssl
find_package(OpenSSL REQUIRED)

add_subdirectory(cipher)
include_directories(cipher)

add_subdirectory(boost)
include_directories(boost)

add_executable(snippets main.cpp cipher/aes.cpp boost/json.cpp boost/json.h)
target_link_libraries(snippets ssl crypto Boost::serialization Boost::filesystem)

add_subdirectory(Boost_tests)

add_subdirectory(jni)
