#pragma once

#include <expected>
#include <memory>
#include <optional>
#include <vector>

#include "github_error.h"
#include "github_repository.h"

namespace jjfp::github_info {

class GitRepositories {
 public:
  static std::expected<GitRepositories, GitError> from_json(
      const std::string& json);

 public:
  GitRepositories();

  u_long size() const;

  std::optional<std::shared_ptr<GitRepository>> at(u_long index) const;

  std::string to_string() const;

 private:
  std::vector<std::shared_ptr<GitRepository>> repositories_;
};

}  // namespace jjfp::github_info