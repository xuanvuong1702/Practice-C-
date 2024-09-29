# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(hello)

add_library(hello src/hello.cpp)

# PUBLIC cần thiết để làm cho cả hello.h và thư viện hello 
# khả dụng ở nơi khác trong dự án
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Yêu cầu trình biên dịch sử dụng các tính năng C++20. 
# Mã không thực sự sử dụng bất kỳ tính năng nào trong số chúng.
target_compile_features(hello PUBLIC cxx_std_20)