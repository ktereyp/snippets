set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Boost_Tests_aes aes_test.cpp)
target_link_libraries(Boost_Tests_aes ${Boost_LIBRARIES} cipher ssl crypto)