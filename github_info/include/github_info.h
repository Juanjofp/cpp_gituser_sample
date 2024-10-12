#pragma once

#include <memory>
#include <optional>
#include <string>

#include "requester.h"

namespace jjfp::github_info {

class GithubInfo {
 public:
  GithubInfo(std::unique_ptr<Requester>& requester, std::string token);

  std::optional<std::string> user() const;

  static std::string print_version();

 private:
  std::unique_ptr<Requester> requester_;

  std::unordered_map<std::string, std::string> headers_;
};

}  // namespace jjfp::github_info