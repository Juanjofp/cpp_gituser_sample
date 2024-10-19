#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "githubrepository.h"
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

TEST_F(GithubTests, CompareSameUsersEqual) {
  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  GitUser other{446496, "Juanjofp", "Juanjofp",
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(me, Eq(other));
}

TEST_F(GithubTests, CompareDifferentUsersNotEqual) {
  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  GitUser other{99999, "Juanjofp2", "Juanjofp2",
                "https://avatars.githubusercontent.com/u/446496?v=4",
                "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(me, Ne(other));
}

TEST_F(GithubTests, GetInformationAboutUserFails) {
  ASSERT_THAT(github_info.user().has_value(), false);
}

TEST_F(GithubTests, GetInformationAboutUser) {
  mock_requester->set_response(mock_requester->get_response("user"));

  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(github_info.user().value(), Eq(me));
}

TEST_F(GithubTests, GetInformationAboutUserRepositoriesFails) {
  ASSERT_THAT(github_info.repositories().has_value(), false);
}

TEST_F(GithubTests, GetInformationAboutUserRepositoriesOk) {
  mock_requester->set_response(mock_requester->get_response("repositories"));

  GitRepository repo{};

  ASSERT_THAT(github_info.repositories().value(), Eq(repo));
}