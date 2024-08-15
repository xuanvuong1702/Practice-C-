add_library(Program STATIC "Program.cpp")

target_include_directories(Program PUBLIC "./")

target_link_libraries(Program PUBLIC MyLib Printer)