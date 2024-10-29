#include "githubapp.h"

#include <iostream>

#include "github_info.h"

namespace jjfp::githubapp {
GithubApp::GithubApp(const std::string& token)
    : github_info_{std::make_unique<GithubInfo>(token)} {
  std::cout << "Creating GithubApp" << std::endl;
}

GithubApp::~GithubApp() { std::cout << "Destroying GithubApp" << std::endl; }

void GithubApp::show_user_info() const {
  if (auto user = github_info_->me(); user.has_value()) {
    std::cout << "Me: " << user.value().to_string() << std::endl;
  } else {
    std::cout << "Failed to get my info" << std::endl;
  }

  if (auto user = github_info_->user("octokit"); user.has_value()) {
    std::cout << "User: " << user.value().to_string() << std::endl;
  } else {
    std::cout << "Failed to get user octokit info" << std::endl;
  }
}

}  // namespace jjfp::githubapp