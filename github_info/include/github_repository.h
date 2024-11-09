#pragma once

#include <expected>
#include <string>

#include "github_error.h"

namespace jjfp::github_info {
class GitRepository {
 public:
  static std::expected<GitRepository, GitError> from_json(
      const std::string& json);

  bool operator==(const GitRepository& other) const;

  std::string to_string() const;
};
}  // namespace jjfp::github_info