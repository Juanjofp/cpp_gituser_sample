#pragma once

#include <optional>
#include <string>

namespace jjfp::github_info {

class GithubUser {
 public:
  static std::optional<GithubUser> from_json(const std::string& json);

  GithubUser(std::string login, int id, std::string avatar_url,
             std::string url);

  bool operator==(const GithubUser& other) const;

  std::string to_string() const;

 private:
  std::string login;
  int id;
  std::string avatar_url;
  std::string url;
};

}  // namespace jjfp::github_info