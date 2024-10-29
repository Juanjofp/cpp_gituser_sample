#pragma once

#include <memory>
#include <optional>
#include <string>

#include "github_info_interface.h"
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
  std::unique_ptr<IGithubInfo> github_info_;
};

}  // namespace jjfp::github_info