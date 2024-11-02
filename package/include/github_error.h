#pragma once

#include <optional>
#include <string>

namespace jjfp::github_info {

class GitUser {
 public:
  static std::optional<GitUser> from_json(const std::string& json);

  GitUser(int id, std::string login, std::string name, std::string avatar_url,
          std::string url);

  bool operator==(const GitUser& other) const;

  std::string to_string() const;

 private:
  int id;
  std::string login;
  std::string name;
  std::string avatar_url;
  std::string url;
};

}  // namespace jjfp::github_info