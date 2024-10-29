#include <iostream>

#include "githubapp.h"

using namespace jjfp::githubapp;

int main() {
  std::cout << "Sample app for GithubInfo lib!" << std::endl;

  std::string test_token{
      "fake_token"};  // This token is not valid, replace it with a valid one

  auto app = GithubApp{test_token};

  app.show_user_info();

  return 0;
}