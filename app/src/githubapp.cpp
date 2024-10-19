#include "githubapp.h"

#include <iostream>

namespace jjfp::githubapp {
GithubApp::GithubApp(const std::string& token) : github_info_{token} {
  std::cout << "Creating GithubApp" << std::endl;
}

GithubApp::~GithubApp() { std::cout << "Destroying GithubApp" << std::endl; }

void GithubApp::show_user_info() const {
  if (auto user = github_info_.user(); user.has_value()) {
    std::cout << "User: " << user.value().to_string() << std::endl;
  } else {
    std::cout << "Failed to get user info" << std::endl;
  }
}

}  // namespace jjfp::githubapp