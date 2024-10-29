#pragma once

#include <optional>
#include <string>

#include "github_repository.h"
#include "github_user.h"

namespace jjfp::github_info {

class IGithubInfo {
 public:
  virtual ~IGithubInfo() = default;

  virtual std::optional<GitUser> user() const = 0;
  virtual std::optional<GitRepository> repositories() const = 0;

  virtual std::string print_version() const = 0;
};

}  // namespace jjfp::github_info