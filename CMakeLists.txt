message("Building Github info project...")

cmake_minimum_required(VERSION 3.29)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
project(github_info_project VERSION 1.0 LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_subdirectory(github_info)

add_subdirectory(app)

# find_package(GTest CONFIG REQUIRED)
# add_subdirectory(soundex)

# add_subdirectory(parser)

# add_subdirectory(soundex2)

# add_subdirectory(chapter4)

# add_subdirectory(concepts)
# add_executable(github_info main.cpp)

# target_link_libraries(modern_cpp PRIVATE soundex parser)