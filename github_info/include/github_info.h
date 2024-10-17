#pragma once

#include <optional>
#include <string>

#include "githubuser.h"

namespace jjfp::github_info {

class GithubInfo {
 public:
  virtual std::optional<GithubUser> user() const = 0;
  virtual std::optional<std::string> repositories() = 0;

  virtual std::string print_version() = 0;
};

}  // namespace jjfp::github_info