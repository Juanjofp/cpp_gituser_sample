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

  static std::string get_response(std::string url);

  void set_response(std::string response);

 private:
  std::string response_ = "";
};

}  // namespace jjfp::github_info::tests