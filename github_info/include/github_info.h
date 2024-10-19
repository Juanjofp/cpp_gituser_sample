#pragma once

#include <optional>
#include <string>

#include "github_info_impl.h"
#include "githubrepository.h"
#include "githubuser.h"

namespace jjfp::github_info {

class GithubInfo {
 public:
  GithubInfo(std::string token);

  std::optional<GitUser> user() const;
  std::optional<GitRepository> repositories();

  std::string print_version();

 private:
  std::unique_ptr<GithubInfoImpl> github_info_;
};

}  // namespace jjfp::github_info