#pragma once

#include <string>

#include "requester.h"

namespace jjfp::github_info::tests {

class MockRequester : public Requester {
 public:
  MockRequester() = default;
  ~MockRequester();

  virtual void init(std::string host) override;

  virtual std::optional<std::string> get(
      const std::string& url,
      const std::unordered_map<std::string, std::string>) override;

  virtual std::optional<std::string> post(const std::string& url,
                                          const std::string& data) override;

  void fail_response(bool fail);

 private:
  static std::string get_response(std::string url);

  bool return_failed_{false};
};

}  // namespace jjfp::github_info::tests