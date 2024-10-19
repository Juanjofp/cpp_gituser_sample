#include "github_info.h"

#include "httplib_requester.h"

namespace jjfp::github_info {

GithubInfo::GithubInfo(std::string token)
    : github_info_{std::make_unique<GithubInfoImpl>(
          std::make_shared<HttpLibRequester>(), token)} {}

std::optional<GitUser> GithubInfo::user() const { return github_info_->user(); }

std::optional<GitRepository> GithubInfo::repositories() const {
  return github_info_->repositories();
}

std::string GithubInfo::print_version() const {
  return github_info_->print_version();
}

}  // namespace jjfp::github_info