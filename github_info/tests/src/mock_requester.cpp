#include "mock_requester.h"

#include <iostream>
#include <unordered_map>

namespace jjfp::github_info::tests {
MockRequester::~MockRequester() {
  std::cout << "?????? Destroying MockRequester" << std::endl;
}

void MockRequester::init(std::string) {}

std::optional<std::string> MockRequester::get(
    const std::string& url,
    const std::unordered_map<std::string, std::string>) {
  if (return_failed_) {
    return_failed_ = false;

    return std::nullopt;
  }

  if (auto res = get_response(url); !res.empty()) {
    return res;
  }

  return std::nullopt;
}

std::optional<std::string> MockRequester::post(const std::string& url,
                                               const std::string& data) {
  return std::optional<std::string>{url + data};
}

void MockRequester::fail_response(bool fail) { return_failed_ = fail; }

std::string MockRequester::get_response(std::string url) {
  std::string user =
      R"({"login":"Juanjofp","id":446496,"node_id":"MDQ6VXNlcjQ0NjQ5Ng==","avatar_url":"https://avatars.githubusercontent.com/u/446496?v=4","gravatar_id":"","url":"https://api.github.com/users/Juanjofp","html_url":"https://github.com/Juanjofp","followers_url":"https://api.github.com/users/Juanjofp/followers","following_url":"https://api.github.com/users/Juanjofp/following{/other_user}","gists_url":"https://api.github.com/users/Juanjofp/gists{/gist_id}","starred_url":"https://api.github.com/users/Juanjofp/starred{/owner}{/repo}","subscriptions_url":"https://api.github.com/users/Juanjofp/subscriptions","organizations_url":"https://api.github.com/users/Juanjofp/orgs","repos_url":"https://api.github.com/users/Juanjofp/repos","events_url":"https://api.github.com/users/Juanjofp/events{/privacy}","received_events_url":"https://api.github.com/users/Juanjofp/received_events","type":"User","site_admin":false,"name":"Juanjo","company":"Digio","blog":"http://juanjofp.com","location":"Murcia, Spain","email":"juanjo@juanjofp.com","hireable":null,"bio":null,"twitter_username":null,"notification_email":"juanjo@juanjofp.com","public_repos":59,"public_gists":5,"followers":35,"following":73,"created_at":"2010-10-20T07:04:01Z","updated_at":"2024-09-07T10:33:10Z"})";

  std::unordered_map<std::string, std::string> responses{
      {"/user", user},
  };

  return responses[url];
}

}  // namespace jjfp::github_info::tests