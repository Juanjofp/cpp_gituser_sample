#include "githubapp.h"

#include <iostream>

#include "github_info.h"

namespace jjfp::githubapp {
GithubApp::GithubApp(const std::string& token)
    : github_info_{std::make_unique<GithubInfo>(token)} {
  std::cout << "Creating GithubApp" << std::endl;
}

GithubApp::~GithubApp() { std::cout << "Destroying GithubApp" << std::endl; }

void GithubApp::show_me_info() const {
  const auto user = github_info_->me();

  if (!user) {
    std::cout << "Failed to get my info" << std::endl;

    const auto error = user.error();

    std::cout << "Error: [" << static_cast<int>(error.kind()) << "] "
              << error.message() << std::endl;

    return;
  }

  std::cout << "My info: " << user->to_string() << std::endl;
}

void GithubApp::show_user_info(const std::string& username) const {
  const auto user = github_info_->user(username);

  if (!user) {
    std::cout << "Failed to get " << username << " info" << std::endl;

    const auto error = user.error();

    std::cout << "Error: [" << static_cast<int>(error.kind()) << "] "
              << error.message() << std::endl;

    return;
  }

  std::cout << username << " info: " << user->to_string() << std::endl;
}

void GithubApp::show_user_repositories(const std::string& username) const {
  const auto repositories = github_info_->repositories(username);

  if (!repositories) {
    std::cout << "Failed to get " << username << " repositories" << std::endl;

    const auto error = repositories.error();

    std::cout << "Error: [" << static_cast<int>(error.kind()) << "] "
              << error.message() << std::endl;

    return;
  }

  std::cout << username << " repositories: [" << repositories->size() << "]"
            << repositories->to_string() << std::endl;
}

}  // namespace jjfp::githubapp