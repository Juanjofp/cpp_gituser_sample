#pragma once

#include <optional>
#include <string>

namespace jjfp::github_info {

class GithubInfo {
 public:
  virtual std::optional<std::string> user() const = 0;

  virtual std::string print_version() = 0;
};

}  // namespace jjfp::github_info