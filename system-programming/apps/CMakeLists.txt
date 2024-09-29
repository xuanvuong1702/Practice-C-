# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(main)

add_executable(main main.c)
# Chúng ta cần hello.h và thư viện hello
target_link_libraries(main
    PRIVATE string_and_struct)

