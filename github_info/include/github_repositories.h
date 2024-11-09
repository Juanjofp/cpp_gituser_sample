#pragma once

#include <expected>

#include "github_error.h"

namespace jjfp::github_info {

class GitRepositories {
 public:
  static std::expected<GitRepositories, GitError> from_json(
      const std::string& json);
};

}  // namespace jjfp::github_info