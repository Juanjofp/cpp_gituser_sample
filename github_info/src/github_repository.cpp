#include "github_repository.h"

#include <json/json.h>

#include "github_user.h"

namespace jjfp::github_info {
std::expected<GitRepository, GitError> GitRepository::from_json(
    const std::string& jsonString) {
  Json::Reader reader;

  Json::Value userMap;

  reader.parse(jsonString, userMap);

  if (userMap.empty()) {
    return std::unexpected(
        GitError{GitError::ErrorKind::InvalidResponse, "Invalid response"});
  }

  if (!userMap.isMember("name")) {
    return std::unexpected(
        GitError{GitError::ErrorKind::MissingField, "Missing field name"});
  }

  const auto name = userMap["name"].asString();

  if (!userMap.isMember("description")) {
    return std::unexpected(GitError{GitError::ErrorKind::MissingField,
                                    "Missing field description"});
  }

  const auto description = userMap["description"].asString();

  return GitRepository{name, description};
}

GitRepository::GitRepository(const std::string& name,
                             const std::string& description)
    : name_{name}, description_{description} {}

bool GitRepository::operator==(const GitRepository& other) const {
  if (this == &other) {
    return true;
  }

  return name_ == other.name_ && description_ == other.description_;
}

std::string GitRepository::get_name() const { return name_; }
std::string GitRepository::get_description() const { return description_; }

std::string GitRepository::to_string() const {
  return std::string{"Name: "} + name_ + std::string{" Description: "} +
         description_;
}

}  // namespace jjfp::github_info
