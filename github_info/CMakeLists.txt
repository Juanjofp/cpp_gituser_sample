message(STATUS "Github info library")

add_library(
  github_info
  STATIC
  src/github_info_impl.cpp
  src/httplib_requester.cpp
  src/github_user.cpp
  src/github_repository.cpp
  src/github_repositories.cpp
  src/github_info.cpp
  src/github_error.cpp
)

target_include_directories(
  github_info
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)

find_package(OpenSSL REQUIRED)
find_package(httplib REQUIRED)
find_package(jsoncpp REQUIRED)

target_link_libraries(
  github_info
  PUBLIC
  OpenSSL::SSL
  OpenSSL::Crypto
  httplib::httplib
  JsonCpp::JsonCpp
)

add_definitions(-DCPPHTTPLIB_OPENSSL_SUPPORT)
add_subdirectory(tests)
