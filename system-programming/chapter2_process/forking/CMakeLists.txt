# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(forking)

add_library(forking src/forking.c)

# PUBLIC cần thiết để làm cho cả hello.h và thư viện hello 
# khả dụng ở nơi khác trong dự án
target_include_directories(${PROJECT_NAME}
    PUBLIC ${forking_SOURCE_DIR}/include)

