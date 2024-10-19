#include <iostream>

#include "github_info_impl.h"
#include "githubapp.h"
#include "httplib_requester.h"

using namespace jjfp::githubapp;

int main() {
  std::cout << "Sample app for GithubInfo lib!" << std::endl;

  std::string test_token{"YOUR_GITHUB_TOKEN"};

  auto app = GithubApp{test_token};

  app.show_user_info();

  return 0;
}