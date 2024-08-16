cmake_minimum_required(VERSION 3.0)

project(RealProject VERSION 1.0 LANGUAGES C CXX) 

set(EXECUTABLE_NAME "RealProject")
set(CUSTOM_LIB_NAME "CustomLib")
set(PRINTER_NAME "Printer")

add_subdirectory(app)
add_subdirectory(src)


