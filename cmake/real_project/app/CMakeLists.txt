add_executable(${EXECUTABLE_NAME} "main.cpp")

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CUSTOM_LIB_NAME})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${PRINTER_NAME})