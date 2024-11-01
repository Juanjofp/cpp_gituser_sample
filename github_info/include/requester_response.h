#pragma once

#include <optional>
#include <string>

namespace jjfp::github_info {
class RequesterResponse {
 public:
  RequesterResponse(int status_code, const std::optional<std::string> &body)
      : body_{body}, status_code_{status_code} {}

  std::optional<std::string> body() const { return body_; }
  int status_code() const { return status_code_; }

 private:
  std::optional<std::string> body_;
  int status_code_;
};

}  // namespace jjfp::github_info