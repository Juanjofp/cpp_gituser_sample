#include "github_info.h"

#include <httplib_requester.h>

namespace jjfp::github_info {

std::string GithubInfo::print_version() { return std::string{"v0.1.0"}; }

GithubInfo::GithubInfo(std::unique_ptr<Requester>& requester, std::string token)
    : requester_{std::move(requester)} {
  requester_->init("https://api.github.com");

  headers_["Accept"] = "application/vnd.github+json";
  headers_["Authorization"] = "Bearer " + token;
  headers_["X-GitHub-Api-Version"] = "2022-11-28";
}

std::optional<std::string> GithubInfo::user() const {
  if (auto res = requester_->get("/user", headers_); res.has_value()) {
    return res;
  }

  return std::nullopt;
}

}  // namespace jjfp::github_info