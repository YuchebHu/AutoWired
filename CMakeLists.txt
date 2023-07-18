cmake_minimum_required(VERSION 3.0.0)
project(AutoWired VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED YES)
set(CXX_EXTENSIONS NO)

file(GLOB HEADERS ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
file(GLOB SRCS ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

include_directories(src)
add_executable(AutoWired main.cpp  ${SRCS})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
