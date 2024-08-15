cmake_minimum_required(VERSION 3.16)


project(SimpleProject VERSION 1.0.0 LANGUAGES C CXX)


add_library(Library STATIC src/hello.cpp)

add_executable(Execuable main.cpp)

target_link_libraries(Execuable PUBLIC Library)