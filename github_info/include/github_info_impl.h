#pragma once

#include <memory>
#include <string>

#include "github_info_interface.h"
#include "requester.h"

namespace jjfp::github_info {

class GithubInfoImpl : public IGithubInfo {
 public:
  GithubInfoImpl(const std::shared_ptr<Requester>& requester,
                 std::string token);
  virtual ~GithubInfoImpl();

  std::expected<GitUser, GitError> me() const override;

  std::expected<GitUser, GitError> user(
      const std::string& username) const override;

  std::expected<GitRepository, GitError> repositories(
      const std::string& username) const override;

  std::string print_version() const override;

 private:
  std::optional<GitError> error_from_response(
      const RequesterResponse& res) const;

  std::expected<std::string, GitError> body_from_response(
      const RequesterResponse& res) const;

  std::expected<GitUser, GitError> user_from_response(
      const RequesterResponse& res) const;

  const std::shared_ptr<Requester> requester_;

  std::unordered_map<std::string, std::string> headers_;
};

}  // namespace jjfp::github_info