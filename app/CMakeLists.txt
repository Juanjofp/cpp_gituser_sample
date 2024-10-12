message(STATUS "Sample app to consume the library")

cmake_minimum_required(VERSION 3.29)

# target_include_directories(github_info PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(github_info_app src/main.cpp)

target_link_libraries(github_info_app PRIVATE github_info)