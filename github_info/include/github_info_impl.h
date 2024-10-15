#pragma once

#include <memory>
#include <optional>
#include <string>

#include "github_info.h"
#include "requester.h"

namespace jjfp::github_info {

class GithubInfoImpl : public GithubInfo {
 public:
  GithubInfoImpl(const std::shared_ptr<Requester>& requester,
                 std::string token);
  ~GithubInfoImpl();

  std::optional<GithubUser> user() const override;

  std::string print_version() override;

 private:
  std::shared_ptr<Requester> requester_;

  std::unordered_map<std::string, std::string> headers_;
};

}  // namespace jjfp::github_info