#pragma once

#include <expected>
#include <string>

#include "github_error.h"
#include "github_repositories.h"
#include "github_user.h"

namespace jjfp::github_info {

class IGithubInfo {
 public:
  virtual ~IGithubInfo() = default;

  virtual std::expected<GitUser, GitError> me() const = 0;

  virtual std::expected<GitUser, GitError> user(
      const std::string& username) const = 0;

  virtual std::expected<GitRepositories, GitError> repositories(
      const std::string& username) const = 0;

  virtual std::string print_version() const = 0;
};

}  // namespace jjfp::github_info