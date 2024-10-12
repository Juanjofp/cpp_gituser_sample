#include <gmock/gmock.h>

#include "github_info.h"
#include "httplib_requester.h"

using namespace testing;

class GithubTests : public Test {
 public:
  std::unique_ptr<jjfp::github_info::Requester> http_lib_requester{
      std::make_unique<jjfp::github_info::HttpLibRequester>()};

  std::string test_token{};

  jjfp::github_info::GithubInfo github_info{http_lib_requester, test_token};
};

TEST_F(GithubTests, ContainsVersion) {
  ASSERT_THAT(github_info.print_version(), StartsWith("v"));
}

TEST_F(GithubTests, PrintVersion) {
  ASSERT_THAT(github_info.print_version(), Eq("v0.1.0"));
}

TEST_F(GithubTests, PrintVersionNotEqual) {
  ASSERT_THAT(github_info.print_version(), Ne("v0.1.1"));
}

TEST_F(GithubTests, GetInformationAboutUser) {
  ASSERT_THAT(github_info.user(), Eq("Juanjo"));
}