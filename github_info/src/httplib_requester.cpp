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

RequesterResponse HttpLibRequester::get(
    const std::string& url,
    const std::unordered_map<std::string, std::string> headers) {
  if (cli_ == nullptr) {
    return RequesterResponse{0, std::nullopt};
  }

  httplib::Headers httpHeader;

  std::for_each(headers.begin(), headers.end(),
                [&httpHeader](const auto& header) {
                  httpHeader.insert({header.first, header.second});
                });

  auto res = cli_->Get(url, httpHeader);

  if (!res) {
    std::cout << "No response received " << res << std::endl;

    return RequesterResponse{0, std::nullopt};
  }

  const auto body =
      res->body != "" ? std::optional<std::string>{res->body} : std::nullopt;

  return RequesterResponse{res->status, body};
}

RequesterResponse HttpLibRequester::post(const std::string&,
                                         const std::string&) {
  if (cli_ == nullptr) {
    return RequesterResponse{0, std::nullopt};
  }

  return RequesterResponse{0, std::nullopt};
}

}  // namespace jjfp::github_info