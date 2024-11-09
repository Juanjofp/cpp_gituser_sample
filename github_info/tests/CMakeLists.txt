message(STATUS "Building github_info unit tests")

add_executable(
  github_info_unit_tests
  src/unit_tests_users.cpp
  src/unit_tests_repos.cpp
  src/mock_requester.cpp
)

target_include_directories(
  github_info_unit_tests
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(
  github_info_unit_tests
  PRIVATE
  github_info
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(github_info_unit_tests)