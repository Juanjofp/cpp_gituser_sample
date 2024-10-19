#pragma once

#include <github_info.h>

#include <string>

namespace jjfp::githubapp {

using namespace jjfp::github_info;

class GithubApp {
 public:
  GithubApp(const std::string& token);
  ~GithubApp();

  void show_user_info() const;

 private:
  GithubInfo github_info_;
};
}  // namespace jjfp::githubapp