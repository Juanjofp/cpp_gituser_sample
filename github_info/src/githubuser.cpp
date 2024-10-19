#include "githubuser.h"

#include <json/json.h>

namespace jjfp::github_info {
std::optional<GitUser> GitUser::from_json(const std::string& jsonString) {
  Json::Reader reader;

  Json::Value userMap;

  reader.parse(jsonString, userMap);

  if (userMap.empty()) {
    return std::nullopt;
  }

  return GitUser{userMap["id"].asInt(), userMap["login"].asString(),
                 userMap["name"].asString(), userMap["avatar_url"].asString(),
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

std::string GitUser::to_string() const {
  return std::string{name + ":" + login + ":" + avatar_url +
                     std::to_string(id) + url};
}

}  // namespace jjfp::github_info