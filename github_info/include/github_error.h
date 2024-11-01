#pragma once

#include <string>

namespace jjfp::github_info {

class GitError {
 public:
  enum class ErrorKind {
    ServerError,
    ResponseError,
    ElementNotFound,
  };

  GitError(const ErrorKind kind, const std::string& message);

  std::string message() const;
  ErrorKind kind() const;

 private:
  ErrorKind kind_;
  std::string message_;
};

}  // namespace jjfp::github_info