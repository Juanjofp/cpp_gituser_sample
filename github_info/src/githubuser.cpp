#include "githubuser.h"

namespace jjfp::github_info {
std::optional<GithubUser> GithubUser::from_json(const std::string&) {
  return GithubUser{"Juanjofp", 446496,
                    "https://avatars.githubusercontent.com/u/446496?v=4",
                    "https://api.github.com/users/Juanjofp"};
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