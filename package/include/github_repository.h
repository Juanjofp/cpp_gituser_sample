#pragma once

#include <optional>
#include <string>

namespace jjfp::github_info {
class GitRepository {
 public:
  static std::optional<GitRepository> from_json(const std::string& json);

  bool operator==(const GitRepository& other) const;

  std::string to_string() const;
};
}  // namespace jjfp::github_info