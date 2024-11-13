#pragma once

#include <expected>
#include <string>

#include "github_error.h"

namespace jjfp::github_info {
class GitRepository {
 public:
  static std::expected<GitRepository, GitError> from_json(
      const std::string& json);

 public:
  GitRepository(const std::string& name, const std::string& description);

  bool operator==(const GitRepository& other) const;

  // Getters
  std::string get_name() const;
  std::string get_description() const;

  std::string to_string() const;

 private:
  std::string name_;
  std::string description_;
};
}  // namespace jjfp::github_info