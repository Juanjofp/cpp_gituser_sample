#include "github_repositories.h"

namespace jjfp::github_info {

std::expected<GitRepositories, GitError> GitRepositories::from_json(
    const std::string&) {
  return std::expected<GitRepositories, GitError>();
}

}  // namespace jjfp::github_info