message(STATUS "Github info library")

add_library(
  github_info
  src/github_info_impl.cpp
  src/httplib_requester.cpp
  src/githubuser.cpp
  src/githubrepository.cpp
  src/github_info.cpp
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
  PRIVATE
  OpenSSL::SSL
  OpenSSL::Crypto
  httplib::httplib
  JsonCpp::JsonCpp
)

add_definitions(-DCPPHTTPLIB_OPENSSL_SUPPORT)
add_subdirectory(tests)
