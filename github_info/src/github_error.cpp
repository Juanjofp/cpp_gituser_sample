#include "github_error.h"

namespace jjfp::github_info {

GitError::GitError(const ErrorKind kind, const std::string& message)
    : kind_{kind}, message_{message} {}

std::string GitError::message() const { return message_; }

GitError::ErrorKind GitError::kind() const { return kind_; }

}  // namespace jjfp::github_info