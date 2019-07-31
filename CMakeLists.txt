cmake_minimum_required(VERSION 3.5)
project(test_ray_plugin)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(test_ray_plugin SHARED test_ray_plugin.cpp)
target_include_directories(test_ray_plugin PUBLIC ${GAZEBO_INCLUDE_DIRS})
target_link_libraries(test_ray_plugin ${GAZEBO_LIBRARIES})
