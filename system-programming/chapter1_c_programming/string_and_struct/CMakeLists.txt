# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(string_and_struct)

add_library(string_and_struct src/string_struct.c)

# PUBLIC cần thiết để làm cho cả hello.h và thư viện hello 
# khả dụng ở nơi khác trong dự án
target_include_directories(${PROJECT_NAME}
    PUBLIC ${string_and_struct_SOURCE_DIR}/include)

