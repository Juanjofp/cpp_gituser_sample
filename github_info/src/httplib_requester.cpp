#include "httplib_requester.h"

namespace jjfp::github_info {
HttpLibRequester::HttpLibRequester() : cli_{nullptr} {
  std::cout << "Creating HttpLibRequester" << std::endl;
}

HttpLibRequester::~HttpLibRequester() {
  cli_->stop();

  std::cout << "Destroying HttpLibRequester" << std::endl;
}

void HttpLibRequester::init(std::string host) {
  cli_ = std::make_unique<httplib::Client>(host);

  cli_->set_follow_location(true);
  cli_->enable_server_certificate_verification(false);
}

std::optional<std::string> HttpLibRequester::get(
    const std::string& url,
    const std::unordered_map<std::string, std::string> headers) {
  if (cli_ == nullptr) {
    return std::nullopt;
  }

  httplib::Headers httpHeader;

  std::for_each(headers.begin(), headers.end(),
                [&httpHeader](const auto& header) {
                  httpHeader.insert({header.first, header.second});
                });

  auto res = cli_->Get(url, httpHeader);

  if (!res) {
    std::cout << "No response received " << res << std::endl;

    return std::nullopt;
  }

  if (res->status >= 200 && res->status < 300) {
    return std::string{res->body};
  }

  std::cout << "Invalid response:" << res->status << " ::>" << res->body
            << std::endl;

  return std::nullopt;
}

std::optional<std::string> HttpLibRequester::post(const std::string& url,
                                                  const std::string& data) {
  if (cli_ == nullptr) {
    return std::nullopt;
  }

  return std::string{url + data};
}

}  // namespace jjfp::github_info