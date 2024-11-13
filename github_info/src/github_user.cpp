#include "github_user.h"

#include <json/json.h>

namespace jjfp::github_info {
std::expected<GitUser, GitError> GitUser::from_json(
    const std::string& jsonString) {
  Json::Reader reader;

  Json::Value userMap;

  reader.parse(jsonString, userMap);

  if (userMap.empty()) {
    return std::unexpected(
        GitError{GitError::ErrorKind::InvalidResponse, "Invalid response"});
  }

  if (!userMap.isMember("id")) {
    return std::unexpected(
        GitError{GitError::ErrorKind::MissingField, "Missing field id"});
  }

  const auto id_value = userMap["id"];

  if (!id_value.isInt()) {
    return std::unexpected(GitError{GitError::ErrorKind::MissingField,
                                    "Missing field id as integer"});
  }

  const auto id = id_value.asInt();

  if (!userMap.isMember("login")) {
    return std::unexpected(
        GitError{GitError::ErrorKind::MissingField, "Missing field login"});
  }

  const auto login = userMap["login"].asString();

  if (!userMap.isMember("name")) {
    return std::unexpected(
        GitError{GitError::ErrorKind::MissingField, "Missing field name"});
  }

  const auto name = userMap["name"].asString();

  return GitUser{id, login, name, userMap["avatar_url"].asString(),
                 userMap["url"].asString()};
}

GitUser::GitUser(int id, std::string login, std::string name,
                 std::string avatar_url, std::string url)
    : id{id}, login{login}, name{name}, avatar_url{avatar_url}, url{url} {}

bool GitUser::operator==(const GitUser& other) const {
  if (this == &other) {
    return true;
  }

  return login == other.login && id == other.id;
}

int GitUser::get_id() const { return id; }

std::string GitUser::get_login() const { return login; }

std::string GitUser::get_name() const { return name; }

std::string GitUser::get_avatar_url() const { return avatar_url; }

std::string GitUser::to_string() const {
  return std::string{name + ":" + login + ":" + avatar_url +
                     std::to_string(id) + url};
}

}  // namespace jjfp::github_info