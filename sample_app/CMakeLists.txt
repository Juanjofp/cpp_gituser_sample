message(STATUS "Sample app to consume the library")

cmake_minimum_required(VERSION 3.29)

add_executable(
  github_info_sample_app
  src/main.cpp
  src/githubapp.cpp
)

target_include_directories(github_info_sample_app PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(github_info_sample_app PRIVATE github_info)