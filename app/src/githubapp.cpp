#include "githubapp.h"

#include <iostream>

namespace jjfp::githubapp {
GithubApp::GithubApp(const GithubInfo& github_info)
    : github_info_{github_info} {
  std::cout << "Creating GithubApp" << std::endl;
}

GithubApp::~GithubApp() { std::cout << "Destroying GithubApp" << std::endl; }

void GithubApp::show_user_info() const {}

}  // namespace jjfp::githubapp