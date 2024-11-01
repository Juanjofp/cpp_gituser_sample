#include <iostream>

#include "githubapp.h"

using namespace jjfp::githubapp;

int main() {
  std::cout << "Sample app for GithubInfo lib!" << std::endl;

  std::string test_token{"fake_token"};

  auto app = GithubApp{test_token};

  app.show_me_info();
  app.show_user_info("octokit");
  app.show_user_repositories("octokit");

  return 0;
}