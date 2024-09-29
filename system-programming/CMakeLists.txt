# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(
    SystemProgrammingCode
    VERSION 0.1
    DESCRIPTION "System Programming code")

add_subdirectory(chapter1_c_programming)   # Tìm CMakeLists.txt trong thư mục con chapter1_c_programming để xử lý
add_subdirectory(apps) 