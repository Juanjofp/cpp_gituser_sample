#pragma once

#include <memory>
#include <string>

#include "github_info_interface.h"

namespace jjfp::githubapp {

using namespace jjfp::github_info;

class GithubApp {
 public:
  GithubApp(const std::string& token);
  ~GithubApp();

  void show_me_info() const;
  void show_user_info(const std::string& username) const;
  void show_user_repositories(const std::string& username) const;

 private:
  std::unique_ptr<IGithubInfo> github_info_;
};
}  // namespace jjfp::githubapp