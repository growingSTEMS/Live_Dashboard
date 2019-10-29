cmake_minimum_required(VERSION 3.0.0)

project(FTC_Live_Dashboard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#setup output directory pathing
set(TARGET_ROOT ${CMAKE_BINARY_DIR}/${CMAKE_SYSTEM_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${TARGET_ROOT}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TARGET_ROOT}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TARGET_ROOT}/bin)

#project wide deps
add_subdirectory(./common_deps/OutputManager)

add_subdirectory(app_logic)
add_subdirectory(interface_gui)
