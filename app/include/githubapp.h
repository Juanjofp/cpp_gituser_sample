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

  void show_user_info() const;

 private:
  std::unique_ptr<IGithubInfo> github_info_;
};
}  // namespace jjfp::githubapp