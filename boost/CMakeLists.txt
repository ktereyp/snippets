set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost COMPONENTS
        serialization filesystem)

include_directories(${Boost_INCLUDE_DIRS})

add_library(boost_t json.cpp json.h)
target_link_libraries(boost_t Boost::serialization Boost::filesystem)
