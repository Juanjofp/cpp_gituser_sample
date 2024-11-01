#include "github_info_impl.h"

#include <iostream>

namespace jjfp::github_info {

std::string GithubInfoImpl::print_version() const {
  return std::string{"v0.1.0"};
}

std::expected<GitUser, GitError> GithubInfoImpl::user_from_response(
    const RequesterResponse &res) const {
  const auto status = res.status_code();

  if (status == 404) {
    return std::unexpected(
        GitError{GitError::ErrorKind::ElementNotFound, "User not found"});
  }

  if (status < 200 || status >= 300) {
    return std::unexpected(
        GitError{GitError::ErrorKind::ServerError,
                 "Server cannot respond with a valid response"});
  }

  if (!res.body()) {
    return std::unexpected(
        GitError{GitError::ErrorKind::ResponseError, "No response body"});
  }

  auto user = GitUser::from_json(*res.body());

  if (!user) {
    return std::unexpected(
        GitError{GitError::ErrorKind::ResponseError, "Invalid response body"});
  }

  return *user;
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

std::expected<GitUser, GitError> GithubInfoImpl::me() const {
  const auto res = requester_->get("/user", headers_);

  return user_from_response(res);
}

std::expected<GitUser, GitError> GithubInfoImpl::user(
    const std::string &username) const {
  auto res = requester_->get(std::format("/users/{}", username), headers_);

  return user_from_response(res);
}

std::expected<GitRepository, GitError> GithubInfoImpl::repositories(
    const std::string &) const {
  return std::unexpected(GitError{GitError::ErrorKind::ElementNotFound,
                                  "Method not implemented yet"});
}

}  // namespace jjfp::github_info