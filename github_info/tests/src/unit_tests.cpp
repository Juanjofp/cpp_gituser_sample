#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "mock_requester.h"

using namespace testing;

class GithubTests : public Test {
 public:
  ~GithubTests() {
    std::cout << "Destroying GithubTests" << std::endl;

    std::cout << "????? Requester references count: "
              << mock_requester.use_count() << std::endl;
  }

  const std::shared_ptr<jjfp::github_info::tests::MockRequester> mock_requester{
      std::make_shared<jjfp::github_info::tests::MockRequester>()};

  std::string test_token{"fake_token"};

  jjfp::github_info::GithubInfoImpl github_info{mock_requester, test_token};
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
  ASSERT_THAT(github_info.user().value(), Eq("Juanjo"));
}

TEST_F(GithubTests, GetInformationAboutUserFails) {
  mock_requester->fail_response(true);

  ASSERT_THAT(github_info.user().has_value(), false);
}