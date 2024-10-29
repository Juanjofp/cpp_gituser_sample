#include <gmock/gmock.h>

#include "github_info_impl.h"
#include "github_repository.h"
#include "github_user.h"
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

TEST_F(GithubTests, GetInformationAboutMeFails) {
  ASSERT_THAT(github_info.me().has_value(), false);
}

TEST_F(GithubTests, GetInformationAboutMe) {
  mock_requester->set_response(mock_requester->get_response("me"));

  GitUser me{446496, "Juanjofp", "Juanjofp",
             "https://avatars.githubusercontent.com/u/446496?v=4",
             "https://api.github.com/users/Juanjofp"};

  ASSERT_THAT(github_info.me().value(), Eq(me));
}

TEST_F(GithubTests, GetInformationAboutUserFails) {
  ASSERT_THAT(github_info.user("juanjofp").has_value(), false);
}

TEST_F(GithubTests, GetInformationAboutUser) {
  mock_requester->set_response(mock_requester->get_response("octokit"));

  GitUser an_user{3430433, "octokit", "octokit",
                  "https://avatars.githubusercontent.com/u/3430433?v=4",
                  "https://api.github.com/users/octokit"};

  ASSERT_THAT(github_info.user("octokit").value(), Eq(an_user));
}

TEST_F(GithubTests, GetInformationAboutUserRepositoriesFails) {
  ASSERT_THAT(github_info.repositories("juanjofp").has_value(), false);
}

TEST_F(GithubTests, GetInformationAboutUserRepositoriesOk) {
  mock_requester->set_response(mock_requester->get_response("repositories"));

  GitRepository repo{};

  ASSERT_THAT(github_info.repositories("juanjofp").value(), Eq(repo));
}