#include "github_info.h"

#include "httplib_requester.h"

namespace jjfp::github_info {

GithubInfo::GithubInfo(std::string token)
    : github_info_{std::make_unique<GithubInfoImpl>(
          std::make_shared<HttpLibRequester>(), token)} {}

std::optional<GitUser> GithubInfo::user() const { return github_info_->user(); }

std::optional<GitRepository> GithubInfo::repositories() {
  return github_info_->repositories();
}

}  // namespace jjfp::github_info