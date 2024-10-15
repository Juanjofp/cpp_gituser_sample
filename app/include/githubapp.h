#pragma once

#include <github_info.h>

#include <string>

namespace jjfp::githubapp {

using namespace jjfp::github_info;

class GithubApp {
 public:
  GithubApp(const GithubInfo& github_info);
  ~GithubApp();

  void show_user_info() const;

 private:
  const GithubInfo& github_info_;
};
}  // namespace jjfp::githubapp