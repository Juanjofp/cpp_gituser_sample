#include <iostream>

#include "github_info.h"
#include "httplib_requester.h"

using namespace jjfp::github_info;

int main() {
  std::cout << "Sample app for GithubInfo lib!" << std::endl;

  std::cout << "Version: " << GithubInfo::print_version() << std::endl;

  std::unique_ptr<Requester> requester = std::make_unique<HttpLibRequester>();

  std::string test_token{};

  GithubInfo github_info{requester, test_token};

  auto user = github_info.user();

  std::cout << "User: " << user.value_or("No user found") << std::endl;

  return 0;
}