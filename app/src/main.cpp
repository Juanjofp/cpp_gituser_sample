#include <iostream>

#include "github_info_impl.h"
#include "githubapp.h"
#include "httplib_requester.h"

using namespace jjfp::githubapp;

int main() {
  std::cout << "Sample app for GithubInfo lib!" << std::endl;

  std::string test_token{"fake_token"};

  auto requester = std::make_shared<jjfp::github_info::HttpLibRequester>();

  auto github_info = jjfp::github_info::GithubInfoImpl{requester, test_token};

  auto app = GithubApp{github_info};

  app.show_user_info();

  return 0;
}