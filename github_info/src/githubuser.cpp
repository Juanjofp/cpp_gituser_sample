#include "githubuser.h"

#include <json/json.h>

namespace jjfp::github_info {
std::optional<GithubUser> GithubUser::from_json(const std::string& jsonString) {
  Json::Reader reader;

  Json::Value userMap;

  reader.parse(jsonString, userMap);

  if (userMap.empty()) {
    return std::nullopt;
  }

  return GithubUser{userMap["login"].asString(), userMap["id"].asInt(),
                    userMap["avatar_url"].asString(),
                    userMap["url"].asString()};
}

GithubUser::GithubUser(std::string login, int id, std::string avatar_url,
                       std::string url)
    : login{login}, id{id}, avatar_url{avatar_url}, url{url} {}

bool GithubUser::operator==(const GithubUser& other) const {
  if (this == &other) {
    return true;
  }

  return login == other.login && id == other.id;
}

std::string GithubUser::to_string() const {
  return std::string{login + ":" + avatar_url + std::to_string(id) + url};
}

}  // namespace jjfp::github_info