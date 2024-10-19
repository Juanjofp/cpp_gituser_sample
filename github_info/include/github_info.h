#pragma once

#include <optional>
#include <string>

#include "github_info_impl.h"
#include "githubrepository.h"
#include "githubuser.h"

namespace jjfp::github_info {

class GithubInfo : public IGithubInfo {
 public:
  GithubInfo(std::string token);
  virtual ~GithubInfo() = default;

  std::optional<GitUser> user() const override;
  std::optional<GitRepository> repositories() const override;

  std::string print_version() const override;

 private:
  std::unique_ptr<GithubInfoImpl> github_info_;
};

}  // namespace jjfp::github_info