#pragma once

#include <string>

#include "requester.h"

namespace jjfp::github_info::tests {

class MockRequester : public Requester {
 public:
  MockRequester();
  ~MockRequester();

  virtual void init(std::string host) override;

  virtual RequesterResponse get(
      const std::string& url,
      const std::unordered_map<std::string, std::string>) override;

  virtual RequesterResponse post(const std::string& url,
                                 const std::string& data) override;

  static std::string get_response(std::string url);

  void set_response(const RequesterResponse& response);

 private:
  std::optional<RequesterResponse> response_;
};

}  // namespace jjfp::github_info::tests