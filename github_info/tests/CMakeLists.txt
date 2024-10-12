message(STATUS "Building github_info unit tests")

add_executable(
  github_info_unit_tests
  unit_tests.cpp
)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(
  github_info_unit_tests
  PRIVATE
  github_info
  httplib::httplib
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(github_info_unit_tests)