# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(
    VscodeCmakeHello
    VERSION 0.1
    DESCRIPTION "Ví dụ CMake nhỏ được build bằng VS Code")

add_subdirectory(hello)   # Tìm CMakeLists.txt trong thư mục con hello để xử lý
add_subdirectory(apps)    # Tìm CMakeLists.txt trong thư mục con apps để xử lý 