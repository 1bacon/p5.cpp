cmake_minimum_required(VERSION 3.1.0)
project(p5cpp VERSION 0.1.0)

#include(CTest)
#enable_testing()

SET(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
