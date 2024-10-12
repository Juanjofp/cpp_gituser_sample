#pragma once

#include <string>
#include <unordered_map>

namespace jjfp::github_info {

class Requester {
 public:
  Requester() = default;
  virtual ~Requester() = default;

  virtual void init(std::string host) = 0;

  virtual std::optional<std::string> get(
      const std::string& url,
      const std::unordered_map<std::string, std::string>) = 0;

  virtual std::optional<std::string> post(const std::string& url,
                                          const std::string& data) = 0;
};

}  // namespace jjfp::github_info