#pragma once

#include <string>
#include <unordered_map>

#include "requester_response.h"

namespace jjfp::github_info {
class Requester {
 public:
  Requester() = default;
  virtual ~Requester() = default;

  virtual void init(std::string host) = 0;

  virtual RequesterResponse get(
      const std::string& url,
      const std::unordered_map<std::string, std::string>) = 0;

  virtual RequesterResponse post(const std::string& url,
                                 const std::string& data) = 0;
};

}  // namespace jjfp::github_info