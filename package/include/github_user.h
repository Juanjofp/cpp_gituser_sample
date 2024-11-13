#pragma once

#include <expected>
#include <string>

#include "github_error.h"

namespace jjfp::github_info {

class GitUser {
 public:
  static std::expected<GitUser, GitError> from_json(const std::string& json);

  GitUser(int id, std::string login, std::string name, std::string avatar_url,
          std::string url);

  bool operator==(const GitUser& other) const;

  // Getters
  int get_id() const;
  std::string get_login() const;
  std::string get_name() const;
  std::string get_avatar_url() const;

  std::string to_string() const;

 private:
  int id;
  std::string login;
  std::string name;
  std::string avatar_url;
  std::string url;
};

}  // namespace jjfp::github_info