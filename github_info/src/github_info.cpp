#include "github_info.h"

#include "github_info_impl.h"
#include "httplib_requester.h"

namespace jjfp::github_info {

GithubInfo::GithubInfo(std::string token)
    : github_info_{std::make_unique<GithubInfoImpl>(
          std::make_shared<HttpLibRequester>(), token)} {}

std::expected<GitUser, GitError> GithubInfo::me() const {
  return github_info_->me();
}

std::expected<GitUser, GitError> GithubInfo::user(
    const std::string& username) const {
  return github_info_->user(username);
}

std::expected<GitRepositories, GitError> GithubInfo::repositories(
    const std::string& username) const {
  return github_info_->repositories(username);
}

std::string GithubInfo::print_version() const {
  return github_info_->print_version();
}

}  // namespace jjfp::github_info