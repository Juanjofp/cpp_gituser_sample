#include "github_info_impl.h"

#include <iostream>

namespace jjfp::github_info {

std::string GithubInfoImpl::print_version() { return std::string{"v0.1.0"}; }

GithubInfoImpl::GithubInfoImpl(const std::shared_ptr<Requester> &requester,
                               std::string token)
    : requester_{requester} {
  requester_->init("https://api.github.com");

  headers_["Accept"] = "application/vnd.github.v3+json";
  headers_["Authorization"] = "Bearer " + token;
  headers_["X-GitHub-Api-Version"] = "2022-11-28";
}

GithubInfoImpl::~GithubInfoImpl() {
  std::cout << "Destroying GithubInfoImpl" << std::endl;
}

std::optional<GithubUser> GithubInfoImpl::user() const {
  if (auto res = requester_->get("/user", headers_); res.has_value()) {
    return GithubUser::from_json(res.value());
  }

  return std::nullopt;
}

std::optional<std::string> GithubInfoImpl::repositories() {
  return std::optional<std::string>{};
}

}  // namespace jjfp::github_info