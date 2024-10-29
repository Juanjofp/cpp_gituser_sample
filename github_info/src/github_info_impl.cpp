#include "github_info_impl.h"

#include <iostream>

namespace jjfp::github_info {

std::string GithubInfoImpl::print_version() const {
  return std::string{"v0.1.0"};
}

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

std::optional<GitUser> GithubInfoImpl::me() const {
  if (auto res = requester_->get("/user", headers_); res.has_value()) {
    return GitUser::from_json(res.value());
  }

  return std::nullopt;
}

std::optional<GitUser> GithubInfoImpl::user(const std::string &username) const {
  if (auto res = requester_->get(std::format("/users/{}", username), headers_);
      res.has_value()) {
    return GitUser::from_json(res.value());
  }

  return std::nullopt;
}

std::optional<GitRepository> GithubInfoImpl::repositories(
    const std::string &) const {
  return GitRepository{};
}

}  // namespace jjfp::github_info