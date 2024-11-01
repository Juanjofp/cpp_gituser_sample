#include "github_repository.h"

#include "github_user.h"

namespace jjfp::github_info {
std::optional<GitRepository> GitRepository::from_json(const std::string&) {
  return std::optional<GitRepository>();
}

bool GitRepository::operator==(const GitRepository&) const { return true; }

std::string GitRepository::to_string() const {
  return std::string{"Not implemted yet"};
}

}  // namespace jjfp::github_info
