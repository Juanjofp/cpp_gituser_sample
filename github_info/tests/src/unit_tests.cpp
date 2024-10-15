#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "githubuser.h"
#include "mock_requester.h"

using namespace testing;
using namespace jjfp::github_info;

class GithubTests : public Test {
 public:
  const std::shared_ptr<tests::MockRequester> mock_requester{
      std::make_shared<tests::MockRequester>()};

  std::string test_token{"fake_token"};

  GithubInfoImpl github_info{mock_requester, test_token};
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

TEST_F(GithubTests, GetInformationAboutUserFails) {
  mock_requester->fail_response(true);

  ASSERT_THAT(github_info.user().has_value(), false);
}

TEST_F(GithubTests, GetInformationAboutUser) {
  GithubUser me{"Juanjofp", 446496,
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(github_info.user().value(), Eq(me));
}
