#pragma once

namespace jjfp::github_info {
class GitRepository {
 public:
  bool operator==(const GitRepository& other) const;
};
}  // namespace jjfp::github_info