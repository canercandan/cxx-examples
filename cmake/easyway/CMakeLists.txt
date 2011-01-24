cmake_minimum_required(VERSION 2.6)

INCLUDE(${CMAKE_SOURCE_DIR}/install.cmake)

PROJECT(test)

INCLUDE_DIRECTORIES(/usr/include)
LINK_DIRECTORIES(/usr/lib)

ADD_EXECUTABLE(test main.cpp)
ADD_DEPENDENCIES(test pthread)

TARGET_LINK_LIBRARIES(test pthread)
