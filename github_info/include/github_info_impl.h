#pragma once

#include <memory>
#include <optional>
#include <string>

#include "github_info_interface.h"
#include "requester.h"

namespace jjfp::github_info {

class GithubInfoImpl : public IGithubInfo {
 public:
  GithubInfoImpl(const std::shared_ptr<Requester>& requester,
                 std::string token);
  virtual ~GithubInfoImpl();

  std::optional<GitUser> user() const override;
  std::optional<GitRepository> repositories() const override;

  std::string print_version() const override;

 private:
  const std::shared_ptr<Requester> requester_;

  std::unordered_map<std::string, std::string> headers_;
};

}  // namespace jjfp::github_info