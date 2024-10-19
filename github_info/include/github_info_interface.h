#pragma once

#include <optional>
#include <string>

#include "githubrepository.h"
#include "githubuser.h"

namespace jjfp::github_info {

class IGithubInfo {
 public:
  virtual std::optional<GitUser> user() const = 0;
  virtual std::optional<GitRepository> repositories() = 0;

  virtual std::string print_version() = 0;
};

}  // namespace jjfp::github_info