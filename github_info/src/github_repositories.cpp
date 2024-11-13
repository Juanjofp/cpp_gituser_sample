#include "github_repositories.h"

#include <json/json.h>

#include <iostream>

namespace jjfp::github_info {

std::expected<GitRepositories, GitError> GitRepositories::from_json(
    const std::string& jsonString) {
  Json::Reader reader;

  Json::Value reposMap;

  reader.parse(jsonString, reposMap);

  if (!reposMap.isArray()) {
    return std::unexpected(GitError{GitError::ErrorKind::InvalidResponse,
                                    "Invalid response. Should be an array"});
  }

  GitRepositories repos{};

  for (const auto& repoValue : reposMap) {
    Json::StreamWriterBuilder writer;
    std::string jsonString = Json::writeString(writer, repoValue);

    const auto repo = GitRepository::from_json(jsonString);

    if (!repo) {
      return std::unexpected(repo.error());
    }

    auto shared_repo = std::make_shared<GitRepository>(*repo);

    repos.repositories_.push_back(shared_repo);
  }

  return repos;
}

GitRepositories::GitRepositories() {}

u_long GitRepositories::size() const { return repositories_.size(); }

std::optional<std::shared_ptr<GitRepository>> GitRepositories::at(
    u_long index) const {
  if (index < 0 || index >= repositories_.size()) {
    return std::nullopt;
  }

  return repositories_[index];
}

std::string GitRepositories::to_string() const {
  std::string result{};

  for (const auto& repo : repositories_) {
    result += repo->to_string();

    result += "\n";
  }

  return result;
}

}  // namespace jjfp::github_info