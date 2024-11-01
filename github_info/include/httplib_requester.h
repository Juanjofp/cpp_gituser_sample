#pragma once

#include <httplib.h>

#include <string>

#include "requester.h"

namespace jjfp::github_info {

class HttpLibRequester : public Requester {
 public:
  HttpLibRequester();
  ~HttpLibRequester();

  virtual void init(std::string host) override;

  virtual RequesterResponse get(
      const std::string& url,
      const std::unordered_map<std::string, std::string>) override;

  virtual RequesterResponse post(const std::string& url,
                                 const std::string& data) override;

 private:
  std::unique_ptr<httplib::Client> cli_;
};

}  // namespace jjfp::github_info