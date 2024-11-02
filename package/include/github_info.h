#pragma once

#include <expected>
#include <memory>
#include <string>

#include "github_info_interface.h"

namespace jjfp::github_info {

class GithubInfo : public IGithubInfo {
 public:
  GithubInfo(std::string token);
  virtual ~GithubInfo() = default;

  std::expected<GitUser, GitError> me() const override;

  std::expected<GitUser, GitError> user(
      const std::string& username) const override;

  std::expected<GitRepository, GitError> repositories(
      const std::string& username) const override;

  std::string print_version() const override;

 private:
  std::unique_ptr<IGithubInfo> github_info_;
};

}  // namespace jjfp::github_info