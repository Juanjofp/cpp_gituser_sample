#include "github_info_impl.h"

#include <iostream>

namespace jjfp::github_info {

std::string GithubInfoImpl::print_version() { return std::string{"v0.1.0"}; }

GithubInfoImpl::GithubInfoImpl(const std::shared_ptr<Requester> &requester,
                               std::string token)
    : requester_{requester} {
  requester_->init("https://api.github.com");

  std::cout << "GithubInfoImpl: Requester references count: "
            << requester.use_count() << std::endl;

  headers_["Accept"] = "application/vnd.github+json";
  headers_["Authorization"] = "Bearer " + token;
  headers_["X-GitHub-Api-Version"] = "2022-11-28";
}

std::optional<std::string> GithubInfoImpl::user() const {
  std::cout << "?????? user() Requester references count: "
            << requester_.use_count() << std::endl;

  if (auto res = requester_->get("/user", headers_); res.has_value()) {
    return res;
  }

  return std::nullopt;
}

}  // namespace jjfp::github_info